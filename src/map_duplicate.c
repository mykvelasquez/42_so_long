/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:57:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/10 13:36:53 by mvelasqu         ###   ########.fr       */
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
			map_info->map_str_dup = NULL;
			return (-1);
		}
		i++;
	}
	map_info->map_str_dup[i] = NULL;
	return (0);
}

int	map_dup(t_map *map_info)
{
	int	i;
	int	j;

	if (!map_info || !map_info->map_str_arr)
		return (-1);
	if (map_info->map_str_dup)
	{
		ft_free_split(map_info->map_str_dup);
		map_info->map_str_dup = NULL;
	}
	if (map_dup_init(map_info) == -1)
		return (-1);
	i = 0;
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
