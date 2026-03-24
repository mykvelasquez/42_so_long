/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:01:37 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 13:40:02 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int find_start(t_map *map_info, t_unit *unit_info)
{
	int i;
	int j;

	i = 0;
	while (i < map_info->y)
	{
		j = 0;
		while (j < map_info->x)
		{
			if(map_info->map_str_dup[i][j] == unit_info->player)
			{
				unit_info->y_player = i;
				unit_info->x_player = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

static void flood_fill(t_map *map_info, t_unit unit_info, int y, int x)
{
	if(y < 0 || y >= map_info->y || x < 0 || x >= map_info->x)
		return ;
	if(map_info->map_str_dup[y][x] == 'V')
		return ;
	if(map_info->map_str_dup[y][x] == unit_info.wall)
		return ;
	map_info->map_str_dup[y][x] = 'V';
	flood_fill(map_info, unit_info, y + 1, x);
	flood_fill(map_info, unit_info, y - 1, x);
	flood_fill(map_info, unit_info, y, x + 1);
	flood_fill(map_info, unit_info, y, x - 1);
}

int map_check_find_path(t_map *map_info, t_unit *unit_info)
{
	char **m_dup;

	if (map_dup(map_info) == -1)
		return (-1);
	if (find_start(map_info, unit_info) == -1)
		return (-1);
	flood_fill(map_info, *unit_info, unit_info->y_player, unit_info->x_player);
	m_dup = map_info->map_str_dup;
	if (map_check_req_char(m_dup, *unit_info, unit_info->exit) == 0)
		return (ft_putendl_fd("Error: Exit inaccessible.", 2), -1);
	if (map_check_req_char(m_dup, *unit_info, unit_info->collectible) == 0)
		return (ft_putendl_fd("Error: Collectible inaccessible.", 2), -1);
	if (map_check_req_char(m_dup, *unit_info, unit_info->space) == 0)
		return (ft_putendl_fd("Error: Some area not accessible.", 2), -1);
	else
	return (0);
}