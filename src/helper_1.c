/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:42 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:44:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(t_map *map_info)
{
	if (!map_info)
		return ;
	if (map_info->map_str)
	{
		free(map_info->map_str);
		map_info->map_str = NULL;
	}
	if (map_info->map_str_arr != NULL)
	{
		ft_free_split(map_info->map_str_arr);
		map_info->map_str_arr = NULL;
	}
	if (map_info->map_str_dup != NULL)
	{
		ft_free_split(map_info->map_str_dup);
		map_info->map_str_dup = NULL;
	}
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
