/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:09:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 10:54:44 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_check_enclosure(t_map *map_info, char c)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_info->y)
	{
		if (map_info->map_str_arr[i][0] != c
			|| map_info->map_str_arr[i][map_info->x - 1] != c)
			return (-1);
		i++;
	}
	j = 0;
	while (j < map_info->x)
	{
		if (map_info->map_str_arr[0][j] != c
			|| map_info->map_str_arr[map_info->y - 1][j] != c)
			return (-1);
		j++;
	}
	return (0);
}

static int	map_check_end_new_line(t_map *map_info)
{
	int		len;

	len = ft_strlen(map_info->map_str);
	if(len > 0 && map_info->map_str[len - 1] == '\n')
		reutrn (-1);
	return (0);
}

static int	map_check_file_format(char **argv)
{
	char	*filetype;
	char	*filename;
	int		i;

	filetype = "ber";
	filename = argv[1];
	i = 0;
	while (filename[i])
		i++;
	i--;
	while (filename[i] != '.' && filename[i])
		i--;
	i++;
	if (ft_strncmp(&filename[i], filetype, 3) != 0)
		return (-1);
	else
		return (0);
}

int		map_validate_format(char **argv, t_map map_info)
{
	if (map_check_enclosure(map_info, unit_info->wall) == -1)
		return (ft_putendl_fd(map_error_str(2), 2), -1);
	if (map_check_end_new_line(map_info) == -1)
		return (ft_putendl_fd(map_error_str(4), 2), -1);
	if (map_check_file_format(argv) == -1)
		return (ft_putendl_fd(map_error_str(5), 2), -1)
	return (0);
}