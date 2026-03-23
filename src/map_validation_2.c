/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:09:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:40:50 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function that checks map.ber if enclosed with char 'c'
int map_check_enclosure(map_data *mapInfo, char c)
{
	int i;
	int j;

	i = 0;
	while(i < mapInfo->y)
	{
		if(mapInfo->map_str_arr[i][0] != c || mapInfo->map_str_arr[i][mapInfo->x - 1] != c)
			return (-1);
		i++;
	}
	j = 0;
	while (j < mapInfo->x)
	{
		if(mapInfo->map_str_arr[0][j] != c || mapInfo->map_str_arr[mapInfo->y - 1][j] != c)
			return (-1);
		j++;
	}
	return 0;
}

static void	map_dup_init(map_data *mapInfo)
{
	int i;

	mapInfo->map_str_dup = malloc(mapInfo->x * sizeof(char *));
	if(!mapInfo->map_str_dup)
		return NULL;
	i = 0;
	while(i < mapInfo->x)
	{
		mapInfo->map_str_dup[i] = (char *)malloc(mapInfo->y * sizeof(char));
		if (!mapInfo->map_str_dup[i])
		{
			free_so_long(mapInfo);
			return (-1);
		}
		i++;
	}
}

void	**map_dup(map_data *mapInfo)
{
	char **dup;
	int i;
	int j;

	i = 0;
	map_dup_init(&mapInfo);
	while(i < mapInfo->x)
	{
		j = 0;
		while(j < mapInfo-> y)
		{
			mapInfo->map_str_arr[i][j] = mapInfo->map_str_dup[i][j];
			j++;
		}
		i++;
	}
}