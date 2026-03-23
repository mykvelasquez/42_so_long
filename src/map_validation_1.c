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
static void	get_map_dimension(map_data *sl)
{
	sl->x = 0;
	sl->y = 0;
	while(sl->map_str_arr[sl->y])
		sl->y++;
	while(sl->map_str_arr[0][sl->x])
		sl->x++;
}

int map_check_rectangle(map_data *sl)
{
	int i;
	
	get_map_dimension(&sl);
	i = 1;
	while(sl->map_str_arr[i])
	{
		if((int)ft_strlen(sl->map_str_arr[i]) != sl->x)
			return (-1);
		i++;
	}
	return (0);
}

// check map if char 'c' EXIST and count is RIGHT. 
int map_check_req_char(map_data *sl, map_unit un, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while(sl->map_str_arr[i])
	{
		j = 0;
		while(sl->map_str_arr[i][j])
		{
			if(sl->map_str_arr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if ((c == un.player || c == un.exit) && count != 1)
		return (-1);
	if (c == un.collectible && count < 1)
		return (-1);
	return (0);
}

int map_check_chars(map_data *sl, map_unit un)
{
	int i;
	int j;

	i = 0;
	while(sl->map_str_arr[i])
	{
		j = 0;
		while(sl->map_str_arr[i][j])
		{
			if(sl->map_str_arr[i][j] != un.player && sl->map_str_arr[i][j] != un.wall
				&& sl->map_str_arr[i][j] != un.exit && sl->map_str_arr[i][j] != un.space
				&& sl->map_str_arr[i][j] != un.collectible)
				return (-1);
			j++;
		}
		i++;
	}
	if (map_check_req_char(&sl, un, un.player) == -1 
		|| map_check_req_char(&sl,un, un.exit) == -1
		|| map_check_req_char(&sl,un, un.collectible) == -1)
		return (-1);
	return (0);
}

// MAIN VALIDATION FUNCTION
int map_validation(map_data *sl, map_unit un)
{
	if(!sl->map_str_arr || !sl->map_str_arr[0])
		return (-1);
	if (map_check_rectangle(&sl) == -1)
		return (-1);
	if (map_check_enclosure(&sl, un.wall) == -1)
		return (-1);
	if (map_check_chars(&sl, un) == -1)
		return (-1); 
	return (0);
}