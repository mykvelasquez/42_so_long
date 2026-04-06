/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:06:36 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 14:28:48 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	map_get_dimension(t_map *map_info)
{
	map_info->x = 0;
	map_info->y = 0;
	while (map_info->map_str_arr[map_info-> y])
		map_info-> y++;
	while (map_info->map_str_arr[0][map_info-> x])
		map_info-> x++;
}


static int		map_check_rectangle(t_map *map_info)
{
	int		i;

	map_get_dimension(map_info);
	i = 1;
	while (map_info->map_str_arr[i])
	{
		if ((int)ft_strlen(map_info->map_str_arr[i]) != map_info->x)
			return (-1);
		i++;
	}
	return (0);
}

static int		map_check_req_char(char **map_arr, t_unit *unit_info, char c)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (map_arr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if ((c == unit_info->player || c == unit_info->exit) && count != 1)
		return (-1);
	if (c == unit_info->collectible && count < 1)
		return (-1);
	if (c == unit_info->collectible)
		unit_info->collect_count = count;
	return (0);
}

static int		map_check_chars(char **map_arr, t_unit *unit_info)
{
	int		i;
	int		j;

	i = 0;
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (map_arr[i][j] != unit_info->player
				&& map_arr[i][j] != unit_info->wall
				&& map_arr[i][j] != unit_info->exit
				&& map_arr[i][j] != unit_info->space
				&& map_arr[i][j] != unit_info->collectible
				&& map_arr[i][j] != unit_info->enemy)
				return (-1);
			j++;
		}
		i++;
	}
	if (map_check_req_char(map_arr, unit_info, unit_info->player) == -1
		|| map_check_req_char(map_arr, unit_info, unit_info->exit) == -1
		|| map_check_req_char(map_arr, unit_info, unit_info->collectible) == -1)
		return (-1);
	return (0);
}

int		map_validation(char **argv, t_map *map_info, t_unit *unit_info)
{
	if (!map_info->map_str_arr || !map_info->map_str_arr[0])
		return (-1);
	if (map_check_rectangle(map_info) == -1)
		return (ft_putendl_fd(map_error_str(1), 2), -1);
	if (map_check_chars(map_info->map_str_arr, unit_info) == -1)
		return (ft_putendl_fd(map_error_str(3), 2), -1);
	if (map_validate_format(argv, map_info) == -1)
		return (ft_putendl_fd(map_error_str(3), 2), -1);
	if (map_validate_path(map_info, unit_info) == -1)
		return (-1);
	return (0);
}
