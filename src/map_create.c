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

static int get_string(m_list *sl, int fd)
{
	char *map_seg;
	char tmp;

	while ((map_seg = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(sl->map,map_seg);
		if(!tmp)
		{
			if (sl->map)
				free_so_long(&sl);
			if (map_seg)
				free (map_seg);
			return (close(fd), ft_putendl_fd("Join Error", 2), -1);
		}
		if(sl->map)
			free_so_long(&sl);
		if(map_seg)
			free(map_seg);
		sl->map = tmp;
	}
	close(fd);
	if (sl->map[0] == '\0')
		return (free_so_long(&sl), ft_putendl_fd("Empty map", 2), -1);
	return (0);
}

static int get_map_string(m_list *sl, char **argv)
{
	int fd;
	char *map_seg;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error opening file", 2), -1);
	sl->map = ft_strdup("");
	if (!sl->map)
		return(close(fd),ft_putendl_fd("malloc Error", 2), -1);
	if(get_string(&sl, fd) == -1)
		return (-1);
	return (0);
}

int create_map(m_list *sl, u_list un, char **argv)
{
	//read map;
	get_map_string(&sl, argv);
	// create map data in **arr
	sl->map_arr = ft_split(sl->map, '\n');
	if(!sl->map_arr)
		return (free_so_long(&sl), ft_putendl_fd("Split Error", 2), 1);
	// validate map size (rectangle)
	if(map_validation(&sl, un) == -1)
		return (free_so_long(&sl), ft_putendl_fd("Split Error", 2), -1);
	return 0;
}