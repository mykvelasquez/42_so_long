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

int		main(int argc, char **argv)
{

	char **map_arr;
	char *map_seg;
	char *map;
	char *tmp;
	int fd;
	int i;

	// number of arguments check
	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	
	// read map
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd("Error opening file", 2), 1);
	map = ft_strdup("");
	if (!map)
		return(close(fd),ft_putendl_fd("malloc Error", 2), 1);
	while ((map_seg = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(map,map_seg);
		if(!tmp)
		{
			if (map)
				free (map);
			if (map_seg)
				free (map_seg);
			close(fd);
			return (ft_putendl_fd("Join Error", 2), 1);
		}
		if(map)
			free(map);
		if(map_seg)
			free(map_seg);
		map = tmp;
	}
	close(fd);
	if (map[0] == '\0')
		return (free(map), ft_putendl_fd("Empty map", 2), 1);
	// create map data in **arr
	map_arr = ft_split(map, '\n');
	if(!map_arr)
		return (free(map), ft_putendl_fd("Split Error", 2), 1);
	// validate map size (rectangle)
	if(map_validation(map_arr) == -1)
		return (ft_free_split(map_arr), free(map), ft_putendl_fd("Split Error", 2), 1);
	// print map
	i = 0;
	while(map_arr && map_arr[i])
	{
		printf("%s\n",map_arr[i]);
		i++;
	}
	ft_free_split(map_arr);
	free (map);
	ft_printf("end of line\n");
	return (0);
}