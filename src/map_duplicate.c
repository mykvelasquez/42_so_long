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

static int	map_dup_init(map_data *mapInfo)
{
	int i;

	mapInfo->map_str_dup = malloc((mapInfo->y + 1) * sizeof(char *));
	if(!mapInfo->map_str_dup)
		return (-1);
	i = 0;
	while(i < mapInfo->y)
	{
		mapInfo->map_str_dup[i] = malloc((mapInfo->x + 1) * sizeof(char));
		if (!mapInfo->map_str_dup[i])
		{
			while (i > 0)
				free(mapInfo->map_str_dup[--i]);
			free(mapInfo->map_str_dup);
			return (-1);
		}
		i++;
	}
	mapInfo->map_str_dup[i] = NULL;
	return (0);
}

int	map_dup(map_data *mapInfo)
{
	int i;
	int j;

	i = 0;
	if (map_dup_init(mapInfo) == -1)
		return (-1);
	while(i < mapInfo->y)
	{
		j = 0;
		while(j < mapInfo->x)
		{
			mapInfo->map_str_dup[i][j] = mapInfo->map_str_arr[i][j];
			j++;
		}
		mapInfo->map_str_dup[i][j] = '\0';
		i++;
	}
	return (0);
}