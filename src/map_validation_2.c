/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:09:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:40:50 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function that checks map.ber if enclosed with char 'c'
int map_check_enclosure(m_list *sl, char c)
{
	int i;
	int j;

	i = 0;
	while(i < sl->y)
	{
		if(sl->map_arr[i][0] != c || sl->map_arr[i][sl->x - 1] != c)
			return (-1);
		i++;
	}
	j = 0;
	while (j < sl->x)
	{
		if(sl->map_arr[0][j] != c || sl->map_arr[sl->y - 1][j] != c)
			return (-1);
		j++;
	}
	return 0;
}

static void	map_dup_init(m_list *sl)
{
	int i;

	sl->map_dup = malloc(sl->x * sizeof(char *));
	if(!sl->map_dup)
		return NULL;
	i = 0;
	while(i < sl->x)
	{
		sl->map_dup[i] = (char *)malloc(sl->y * sizeof(char));
		if (!sl->map_dup[i])
		{
			free_so_long(sl);
			return (-1);
		}
		i++;
	}
}

void	**map_dup(m_list *sl)
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
			sl->map_arr[i][j] = sl->map_dup[i][j];
			j++;
		}
		i++;
	}
}