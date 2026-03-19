/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/18 14:10:51 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_so_long(l_list *sl)
{
	ls->x = 0;
	ls->y = 0;
	ls->map = NULL;
	ls->map_arr = NULL;
}

void	free_so_long(l_list *sl)
{
	if (ls->x != 0)
		ls->x = 0;
	if (ls->y != 0)
		ls->y = 0;
	if (ls->map != NULL)
	{
		free(ls->map);
		ls->map = NULL;
	}
	if (ls->map_arr != NULL)
	{
		ft_free_split(ls->map_arr);
		ls->map_arr = NULL;
	}
}

int get_string(l_list *sl, int fd)
{
	char *map_seg;

	while ((map_seg = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(ls->map,map_seg);
		if(!tmp)
		{
			if (ls->map)
				free_so_long(&sl);
			if (map_seg)
				free (map_seg);
			close(fd);
			return (ft_putendl_fd("Join Error", 2), -1);
		}
		if(ls->map)
			free_so_long(&sl);
		if(map_seg)
			free(map_seg);
		ls->map = tmp;
	}
	close(fd);
	if (ls->map[0] == '\0')
		return (free_so_long(&sl), ft_putendl_fd("Empty map", 2), -1);
	return (0);
}

int get_map_string(l_list *sl, char **argv)
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

int create_map(l_list sl)
{
	sl->map_arr = ft_split(sl->map, '\n');
	if(!sl->map_arr)
		return (free_so_long(&sl), ft_putendl_fd("Split Error", 2), 1);
	// validate map size (rectangle)
	if(map_validation(&sl) == -1)
		return (free_so_long(&sl), ft_putendl_fd("Split Error", 2), -1);
	return 0;
}

void	print_map(l_list sl)
{
	int i;

	i = 0;
	while(sl->map_arr && sl->map_arr[i])
	{
		ft_printf("%s\n",sl->map_arr[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	l_list sl;

	// number of arguments check
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	// read map
	get_map_string(&sl, argv);
	// create map data in **arr
	create_map(&sl);
	// print map
	print_map(&sl);
	free_so_long(&sl);
	ft_printf("end of line\n");
	return (0);
}