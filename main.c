/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/10 13:36:47 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map_info;
	t_unit	unit_info;
	t_game	game;

	if (argc != 2)
		return (ft_putendl_fd(map_error_str(0), 2), 1);
	if (start_so_long(argc, argv, &map_info, &unit_info) == -1)
		return (map_free(&map_info), 1);
	if (start_game_so_long(&game, &map_info, &unit_info) == -1)
		return (game_cleanup(&game), map_free(&map_info), 1);
	game_render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, game_key_handler, &game);
	mlx_hook(game.win, 17, 0, game_key_close_x, &game);
	mlx_loop_hook(game.mlx, game_animate, &game);
	mlx_loop(game.mlx);
	game_exit(&game);
	return (0);
}
