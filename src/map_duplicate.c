/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:57:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:44:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_dup_init(t_map *map_info)
{
	int		i;

	map_info->map_str_dup = malloc((map_info->y + 1) * sizeof(char *));
	if (!map_info->map_str_dup)
		return (-1);
	i = 0;
	while (i < map_info->y)
	{
		map_info->map_str_dup[i] = malloc((map_info->x + 1) * sizeof(char));
		if (!map_info->map_str_dup[i])
		{
			while (i > 0)
				free(map_info->map_str_dup[--i]);
			free(map_info->map_str_dup);
			return (-1);
		}
		i++;
	}
	map_info->map_str_dup[i] = NULL;
	return (0);
}

int	map_dup(t_map *map_info)
{
	int		i;
	int		j;

	i = 0;
	if (map_dup_init(map_info) == -1)
		return (-1);
	while (i < map_info->y)
	{
		j = 0;
		while (j < map_info->x)
		{
			map_info->map_str_dup[i][j] = map_info->map_str_arr[i][j];
			j++;
		}
		map_info->map_str_dup[i][j] = '\0';
		i++;
	}
	return (0);
}
