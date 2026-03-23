/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:09:39 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 11:40:50 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function that checks map.ber if enclosed with char 'c'
int map_check_enclosure(map_data *mapInfo, char c)
{
	int i;
	int j;

	i = 0;
	while(i < mapInfo->y)
	{
		if(mapInfo->map_str_arr[i][0] != c 
			|| mapInfo->map_str_arr[i][mapInfo->x - 1] != c)
			return (-1);
		i++;
	}
	j = 0;
	while (j < mapInfo->x)
	{
		if(mapInfo->map_str_arr[0][j] != c 
			|| mapInfo->map_str_arr[mapInfo->y - 1][j] != c)
			return (-1);
		j++;
	}
	return 0;
}

