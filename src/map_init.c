/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:43:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/01 11:30:52 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_map *map_info, t_unit *unit_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->map_str = NULL;
	map_info->map_str_arr = NULL;
	map_info->map_str_dup = NULL;
	unit_info->player = 'P';
	unit_info->exit = 'E';
	unit_info->wall = '1';
	unit_info->space = '0';
	unit_info->collectible = 'C';
	unit_info->enemy = 'X';
	unit_info->x_player = 0;
	unit_info->y_player = 0;
	unit_info->x_exit = 0;
	unit_info->y_exit = 0;
	unit_info->collect_count = 0;
}

int start_so_long(int argc, char **argv, t_map *map_info, t_unit *unit_info)
{
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), -1);
	init_so_long(map_info, unit_info);
	if (map_create(map_info, unit_info, argv) == -1)
		return (map_free(map_info), -1);
	map_print(map_info->map_str_arr);
	printf("start y = %d ; x = %d\n", unit_info->y_player, unit_info->x_player);
	ft_printf("\n");
	if (map_dup(map_info) == -1)
		return (map_free(map_info), -1);
	return 0;
}
