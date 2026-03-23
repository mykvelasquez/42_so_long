/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:47:19 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 12:25:41 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int get_string(map_data *mapInfo, int fd)
{
	char	*map_seg;
	char	*tmp;

	while ((map_seg = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(mapInfo->map_str, map_seg);
		if (!tmp)
		{
			free(map_seg);
			close(fd);
			return (ft_putendl_fd("Join Error", 2), -1);
		}
		free(mapInfo->map_str);
		free(map_seg);
		mapInfo->map_str = tmp;
	}
	close(fd);
	if (mapInfo->map_str[0] == '\0')
		return (ft_putendl_fd("Empty map", 2), -1);
	return (0);
}

static int get_map_string(map_data *mapInfo, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error opening file", 2), -1);
	mapInfo->map_str = ft_strdup("");
	if (!mapInfo->map_str)
		return(close(fd),ft_putendl_fd("malloc Error", 2), -1);
	if(get_string(mapInfo, fd) == -1)
		return (-1);
	return (0);
}

int create_map(map_data *mapInfo, map_unit unitInfo, char **argv)
{
	//read map;
	if(get_map_string(mapInfo, argv) == -1)
		return (ft_putendl_fd("Map Str Error", 2), 1);
	// create map data in **arr
	mapInfo->map_str_arr = ft_split(mapInfo->map_str, '\n');
	if(!mapInfo->map_str_arr)
		return (ft_putendl_fd("Split Error", 2), 1);
	// validate map size (rectangle)
	if(map_validation(mapInfo, unitInfo) == -1)
		return (ft_putendl_fd("Map Validation Error", 2), -1);
	return 0;
}