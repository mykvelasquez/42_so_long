/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:46:42 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 12:54:21 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_so_long(t_map *map_info)
{
	if (!map_info)
		return ;
	if (map_info->map_str)
	{
		free(map_info->map_str);
		map_info->map_str = NULL;
	}
	if (map_info->map_str_arr != NULL)
	{
		ft_free_split(map_info->map_str_arr);
		map_info->map_str_arr = NULL;
	}
	if (map_info->map_str_dup != NULL)
	{
		ft_free_split(map_info->map_str_dup);
		map_info->map_str_dup = NULL;
	}
}

char	*ft_map_error(int error)
{
	ft_printf("Error: ");
	if (error == 1)
		return ("Map not rectangle");
	else if (error == 2)
		return ("Map not enclosed");
	else if (error == 3)
		return ("Map does not meet required unit number");
	else if (error == 4)
		return ("Map has a new line at the end");
	else if (error == 5)
		return ("file not in proper format");
	else
		return (0);
}

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	cleanup_game(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}