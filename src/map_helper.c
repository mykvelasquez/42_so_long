/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:42 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 14:16:47 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_free(t_map *map_info)
{
	if (!map_info)
		return ;
	if (map_info->map_str)
	{
		free(map_info->map_str);
		map_info->map_str = NULL;
	}
	if (map_info->map_str_arr)
	{
		ft_free_split(map_info->map_str_arr);
		map_info->map_str_arr = NULL;
	}
	if (map_info->map_str_dup)
	{
		ft_free_split(map_info->map_str_dup);
		map_info->map_str_dup = NULL;
	}
}

char	*map_error_str(int error)
{
	ft_printf("Error: ");
	if (error == 1)
		return ("Map not rectangle");
	else if (error == 2)
		return ("Map not enclosed");
	else if (error == 3)
		return ("Map does not meet required unit number");
	else if (error == 4)
		return ("Map has a new line at the end");
	else if (error == 5)
		return ("file not in proper format");
	else
		return ("error not found");
}

void	map_print(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

