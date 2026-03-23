/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:57:49 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:58:11 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_dup_init(map_data *sl)
{
	int i;

	sl->map_str_dup = malloc(sl->x * sizeof(char *));
	if(!sl->map_str_dup)
		return NULL;
	i = 0;
	while(i < sl->x)
	{
		sl->map_str_dup[i] = (char *)malloc(sl->y * sizeof(char));
		if (!sl->map_str_dup[i])
		{
			free_so_long(sl);
			return (-1);
		}
		i++;
	}
}

void	map_dup(map_data *sl)
{
	char **dup;
	int i;
	int j;

	i = 0;
	map_dup_init(&sl);
	while(i < sl->x)
	{
		j = 0;
		while(j < sl-> y)
		{
			sl->map_str_arr[i][j] = sl->map_str_dup[i][j];
			j++;
		}
		i++;
	}
}