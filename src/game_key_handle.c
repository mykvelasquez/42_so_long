/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:09:04 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/06 14:42:06 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int	game_print_key(int key, void *p)
//{
//	(void)p;
//	return (printf("Key %c : %d\n",key, key));
//}

int	game_key_handler(int key, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (key == 65307)
		game_exit(game);
	game_handle_move_key(key, game);
	return (0);
}

int game_key_close_x(void *p)
{
	t_game *game;
	game = (t_game *)p;

	game_exit(game);
	return 0;
}

