/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:47:19 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/10 13:19:43 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_string(t_map *map_info)
{
	char	*map_seg;
	char	*tmp;

	map_seg = get_next_line(map_info->fd);
	while (map_seg != NULL)
	{
		tmp = ft_strjoin(map_info->map_str, map_seg);
		if (!tmp)
		{
			free(map_seg);
			return (close(map_info->fd), ft_putendl_fd("Join Error", 2), -1);
		}
		free(map_info->map_str);
		free(map_seg);
		map_info->map_str = tmp;
		map_seg = get_next_line(map_info->fd);
	}
	close(map_info->fd);
	if (map_info->map_str[0] == '\0')
		return (ft_putendl_fd("Error: Empty map", 2), -1);
	return (0);
}

static int	map_get_string(t_map *map_info, char **argv)
{
	map_info->fd = open(argv[1], O_RDONLY);
	if (map_info->fd == -1)
		return (ft_putendl_fd("Error: File not open", 2), -1);
	map_info->map_str = ft_strdup("");
	if (!map_info-> map_str)
		return (close(map_info-> fd), -1);
	if (get_string(map_info) == -1)
		return (-1);
	return (0);
}

static int	map_find_start(t_map *map_info, t_unit *unit_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->y)
	{
		j = 0;
		while (j < map_info->x)
		{
			if (map_info->map_str_arr[i][j] == unit_info->player)
			{
				unit_info->y_player = i;
				unit_info->x_player = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

static int	map_find_exit(t_map *map_info, t_unit *unit_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->y)
	{
		j = 0;
		while (j < map_info->x)
		{
			if (map_info->map_str_arr[i][j] == unit_info->exit)
			{
				unit_info->y_exit = i;
				unit_info->x_exit = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	map_create(t_map *map_info, t_unit *unit_info, char **argv)
{
	if (map_check_file_format(argv) == -1)
		return (ft_putendl_fd(map_error_str(5), 2), -1);
	if (map_get_string(map_info, argv) == -1)
		return (-1);
	map_info->map_str_arr = ft_split(map_info->map_str, '\n');
	if (!map_info->map_str_arr)
		return (ft_putendl_fd("Error: Split", 2), -1);
	if (map_validation(map_info, unit_info) == -1)
		return (-1);
	if (map_find_start(map_info, unit_info) == -1)
		return (ft_putendl_fd("Error: start", 2), -1);
	if (map_find_exit(map_info, unit_info) == -1)
		return (ft_putendl_fd("Error: exit", 2), -1);
	if (map_validate_path(map_info, unit_info) == -1)
		return (-1);
	return (0);
}
