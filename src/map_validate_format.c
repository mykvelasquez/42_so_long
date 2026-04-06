/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:09:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/06 14:21:10 by mvelasqu         ###   ########.fr       */
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
		return (-1);
	return (0);
}

int	map_check_file_format(char **argv)
{
	char	*filename;
	int		i;

	filename = argv[1];
	i = ft_strlen(filename) - 1;
	while(i > 0 && filename[i] != '.')
		i--;
	if (i < 0)
		return (-1);
	if (ft_strncmp(&filename[i + 1], "ber", 3) != 0)
		return (-1);
	if (filename[i + 4] != '\0')
		return (-1);
	return (0);
}

int		map_validate_format(t_map *map_info)
{
	if (map_check_enclosure(map_info, '1') == -1)
		return (ft_putendl_fd(map_error_str(2), 2), -1);
	if (map_check_end_new_line(map_info) == -1)
		return (ft_putendl_fd(map_error_str(4), 2), -1);
	return (0);
}