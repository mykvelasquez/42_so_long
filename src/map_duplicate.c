/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:57:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:58:11 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	map_dup(map_data *mapInfo)
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