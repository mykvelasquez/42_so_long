/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:06:36 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 12:30:36 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check map if RECTANGLE, get max y and x
static void	get_map_dimension(map_data *mapInfo)
{
	mapInfo->x = 0;
	mapInfo->y = 0;
	while(mapInfo->map_str_arr[mapInfo->y])
		mapInfo->y++;
	while(mapInfo->map_str_arr[0][mapInfo->x])
		mapInfo->x++;
}

int map_check_rectangle(map_data *mapInfo)
{
	int i;
	
	get_map_dimension(mapInfo);
	i = 1;
	while(mapInfo->map_str_arr[i])
	{
		if((int)ft_strlen(mapInfo->map_str_arr[i]) != mapInfo->x)
			return (-1);
		i++;
	}
	return (0);
}

// check map if char 'c' EXIST and count is RIGHT. 
int map_check_req_char(map_data *mapInfo, map_unit unitInfo, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while(mapInfo->map_str_arr[i])
	{
		j = 0;
		while(mapInfo->map_str_arr[i][j])
		{
			if(mapInfo->map_str_arr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if ((c == unitInfo.player || c == unitInfo.exit) && count != 1)
		return (-1);
	if (c == unitInfo.collectible && count < 1)
		return (-1);
	return (0);
}

int map_check_chars(map_data *mapInfo, map_unit unitInfo)
{
	int i;
	int j;

	i = 0;
	while(mapInfo->map_str_arr[i])
	{
		j = 0;
		while(mapInfo->map_str_arr[i][j])
		{
			if(mapInfo->map_str_arr[i][j] != un.player && mapInfo->map_str_arr[i][j] != un.wall
				&& mapInfo->map_str_arr[i][j] != un.exit && mapInfo->map_str_arr[i][j] != un.space
				&& mapInfo->map_str_arr[i][j] != un.collectible)
				return (-1);
			j++;
		}
		i++;
	}
	if (map_check_req_char(mapInfo, unitInfo, unitInfo.player) == -1 
		|| map_check_req_char(mapInfo, unitInfo, unitInfo.exit) == -1
		|| map_check_req_char(mapInfo, unitInfo, unitInfo.collectible) == -1)
		return (-1);
	return (0);
}

// MAIN VALIDATION FUNCTION
int map_validation(map_data *mapInfo, map_unit unitInfo)
{
	if(!mapInfo->map_str_arr || !mapInfo->map_str_arr[0])
		return (-1);
	if (map_check_rectangle(mapInfo) == -1)
		return (-1);
	if (map_check_enclosure(mapInfo, unitInfo.wall) == -1)
		return (-1);
	if (map_check_chars(mapInfo, unitInfo) == -1)
		return (-1); 
	return (0);
}