/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:06:36 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/18 14:20:34 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_check_rectangle(char **map_arr)
{
	int width;
	int i;

	if(!map_arr || !map_arr[0])
		return (-1);
	width = ft_strlen(map_arr[0]);
	i = 1;
	while(map_arr[i])
	{
		if((int)ft_strlen(map_arr[i]) != width)
			return (-1);
		i++;
	}
	return (0);
}

int map_validation(char **map_arr)
{
	if(map_check_rectangle(map_arr) == -1)
		return (-1);
	return (0);
}