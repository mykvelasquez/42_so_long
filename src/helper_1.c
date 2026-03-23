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

void	free_so_long(map_data *mapInfo)
{
	if (!mapInfo)
		return;
	if (mapInfo->map_str)
	{
		free(mapInfo->map_str);
		mapInfo->map_str = NULL;
	}
	if (mapInfo->map_str_arr != NULL)
	{
		ft_free_split(mapInfo->map_str_arr);
		mapInfo->map_str_arr = NULL;
	}
	if (mapInfo->map_str_dup != NULL)
	{
		ft_free_split(mapInfo->map_str_dup);
		mapInfo->map_str_dup = NULL;
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