/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:01:37 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/16 09:48:49 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_map *map_info, t_unit unit_info, int y, int x)
{
	if (y < 0 || y >= map_info->y || x < 0 || x >= map_info->x)
		return ;
	if (map_info->map_str_dup[y][x] == 'V')
		return ;
	if (map_info->map_str_dup[y][x] == 'X')
		return ;
	if (map_info->map_str_dup[y][x] == unit_info.wall)
		return ;
	map_info->map_str_dup[y][x] = 'V';
	flood_fill(map_info, unit_info, y + 1, x);
	flood_fill(map_info, unit_info, y - 1, x);
	flood_fill(map_info, unit_info, y, x + 1);
	flood_fill(map_info, unit_info, y, x - 1);
}

static int	map_has_char(char **map_dup, char c)
{
	int		i;
	int		j;

	i = 0;
	while (map_dup[i])
	{
		j = 0;
		while (map_dup[i][j])
		{
			if (map_dup[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_validate_path(t_map *map_info, t_unit *unit_info)
{
	char	**m_dup;

	if (map_dup(map_info) == -1)
		return (-1);
	m_dup = map_info->map_str_dup;
	flood_fill(map_info, *unit_info, unit_info->y_player, unit_info->x_player);
	if (map_has_char(m_dup, unit_info->exit))
		return (ft_putendl_fd("Error: Exit inaccessible.", 2), -1);
	if (map_has_char(m_dup, unit_info->collectible))
		return (ft_putendl_fd("Error: Collectible inaccessible.", 2), -1);
	if (map_has_char(m_dup, unit_info->enemy))
		return (ft_putendl_fd("Error: Enemy inaccessible.", 2), -1);
	if (map_has_char(m_dup, 'P'))
		return (ft_putendl_fd("Error: Player inaccessible.", 2), -1);
	if (map_has_char(m_dup, unit_info->space))
		return (ft_putendl_fd("Error: Space inaccessible.", 2), -1);
	return (0);
}
