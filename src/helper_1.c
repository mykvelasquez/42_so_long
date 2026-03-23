/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:42 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:47:06 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(m_list *sl)
{
	if (sl->map != NULL)
	{
		free(sl->map);
		sl->map = NULL;
	}
	if (sl->map_arr != NULL)
	{
		ft_free_split(sl->map_arr);
		sl->map_arr = NULL;
	}
	if (sl->map_dup != NULL)
	{
		ft_free_split(sl->map_dup);
		sl->map_dup = NULL;
	}
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while(map && map[i])
	{
		ft_printf("%s\n",map[i]);
		i++;
	}
}