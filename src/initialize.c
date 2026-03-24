/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:43:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:45:00 by mvelasqu         ###   ########.fr       */
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
}
