/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 12:23:56 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	map_data	mapInfo;
	map_unit	unitInfo;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	init_so_long(&mapInfo, &unitInfo);
	if (create_map(&mapInfo, unitInfo, argv) == -1)
		return (free_so_long(&mapInfo), 1);
	print_map(mapInfo.map_str_arr);
	ft_printf("\n");
	if (map_dup(&mapInfo) == -1)
		return (free_so_long(&mapInfo), 1);
	print_map(mapInfo.map_str_dup);
	free_so_long(&mapInfo);
	return (0);
}