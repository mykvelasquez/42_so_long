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

int		main(int argc, char **argv)
{
	map_data mapInfo;
	map_unit unitInfo;

	// number of arguments check
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	init_so_long(&mapInfo, &unitInfo);
	// create map data in **arr
	create_map(&mapInfo, unitInfo, argv);
	// print map
	print_map(mapInfo.map_arr);
	ft_printf("\n");
	// create dup map for checking
	map_dup(&mapInfo);
	print_map(mapInfo.map_dup);
	// free everything!
	free_so_long(&mapInfo);
	ft_printf("end of line\n");
	return (0);
}