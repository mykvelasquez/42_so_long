/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:43:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:48:40 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_so_long(map_data *mapInfo, map_unit *unitInfo)
{
	mapInfo->x = 0;
	mapInfo->y = 0;
	mapInfo->map_str = NULL;
	mapInfo->map_str_arr = NULL;
	mapInfo->map_str_dup = NULL;
	unitInfo->player = 'P';
	unitInfo->exit = 'E';
	unitInfo->wall = '1';
	unitInfo->space = '0';
	unitInfo->collectible = 'C';
}