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

void init_so_long(m_list *sl, u_list *un)
{
	sl->x = 0;
	sl->y = 0;
	sl->map = NULL;
	sl->map_arr = NULL;
	sl->map_dup = NULL;
	un->player = 'P';
	un->exit = 'E';
	un->wall = '1';
	un->space = '0';
	un->collectible = 'C';
}