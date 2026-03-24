/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:47:19 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:45:00 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_string(t_map *map_info, int fd)
{
	char	*map_seg;
	char	*tmp;

	map_seg = get_next_line(fd);
	while (map_seg != NULL)
	{
		tmp = ft_strjoin(map_info->map_str, map_seg);
		if (!tmp)
		{
			free(map_seg);
			return (close(fd), ft_putendl_fd("Join Error", 2), -1);
		}
		free(map_info->map_str);
		free(map_seg);
		map_info->map_str = tmp;
	}
	close(fd);
	if (map_info->map_str[0] == '\0')
		return (ft_putendl_fd("Empty map", 2), -1);
	return (0);
}

static int	get_map_string(t_map *map_info, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error opening file", 2), -1);
	map_info->map_str = ft_strdup("");
	if (!map_info->map_str)
		return (close(fd), ft_putendl_fd("malloc Error", 2), -1);
	if (get_string(map_info, fd) == -1)
		return (-1);
	return (0);
}

int	create_map(t_map *map_info, t_unit unit_info, char **argv)
{
	if (get_map_string(map_info, argv) == -1)
		return (ft_putendl_fd("Map Str Error", 2), 1);
	map_info->map_str_arr = ft_split(map_info->map_str, '\n');
	if (!map_info->map_str_arr)
		return (ft_putendl_fd("Split Error", 2), 1);
	if (map_validation(map_info, unit_info) == -1)
		return (ft_putendl_fd("Map Validation Error", 2), -1);
	return (0);
}
