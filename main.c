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
	m_list sl;
	u_list un;

	// number of arguments check
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	init_so_long(&sl, &un);
	// create map data in **arr
	create_map(&sl, un, argv);
	// print map
	print_map(sl.map_arr);
	ft_printf("\n");
	// create dup map for checking
	map_dup(&sl);
	print_map(sl.map_dup);
	// free everything!
	free_so_long(&sl);
	ft_printf("end of line\n");
	return (0);
}