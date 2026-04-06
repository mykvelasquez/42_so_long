/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/06 13:20:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int game_animate(void *p)
{
    t_game  *game;

    game = (t_game *)p;

    game->anim_count++;
    if (game->anim_count >= 30000)
    {
        game->anim_count = 0;
        if (game->anim_frame == 0)
            game->anim_frame = 1;
        else
            game->anim_frame = 0;
        game_render_map(game);
        game_print_move(game);
    }
    return (0);
}