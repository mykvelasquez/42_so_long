/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:45:00 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_info;
	t_unit	unit_info;

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	init_so_long(&map_info, &unit_info);
	if (create_map(&map_info, unit_info, argv) == -1)
		return (free_so_long(&map_info), 1);
	print_map(map_info.map_str_arr);
	ft_printf("\n");
	if (map_dup(&map_info) == -1)
		return (free_so_long(&map_info), 1);
	print_map(map_info.map_str_dup);
	free_so_long(&map_info);
	return (0);
}
