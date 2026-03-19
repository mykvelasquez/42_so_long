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

void	get_map_dimension(l_list *sl)
{
	sl->x = 0;
	sl->y = 0;
	while(sl->map_arr[sl->y])
		sl->y++;
	while(sl->map_arr[0][sl->x])
		sl->x++;
}

int map_check_rectangle(l_list *sl)
{
	int i;
	
	get_map_dimension(&sl);
	i = 1;
	while(sl->map_arr[i])
	{
		if((int)ft_strlen(sl->map_arr[i]) != sl->x)
			return (-1);
		i++;
	}
	return (0);
}

int map_check_req_char(list *sl, char c)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	while(sl->map_arr[i])
	{
		j = 0;
		while(sl->map_arr[i][j])
		{
			if(sl->map_arr[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if ((c == 'P' || c == 'E') && count != 1)
		return (-1);
	if (c == 'C' && count < 1)
		return (-1);
	return (0);
}

int map_check_chars(list *sl)
{
	int i;
	int j;

	i = 0;
	while(sl->map_arr[i])
	{
		j = 0;
		while(sl->map_arr[i][j])
		{
			if(sl->map_arr[i][j] != '0' && sl->map_arr[i][j] != '1'
				&& sl->map_arr[i][j] != 'C' && sl->map_arr[i][j] != 'E'
				&& sl->map_arr[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
	}
	if (map_check_req_char(&sl,'P') == -1 
		|| map_check_req_char(&sl,'E') == -1
		|| map_check_req_char(&s,'C') == -1)
		return (-1);
	return (0);
}


int map_check_enclosure(l_list *sl, char c)
{
	int i;
	int j;

	i = 0;
	while(i < sl->y)
	{
		if(sl->map_arr[i][0] != c || sl->map_arr[i][sl->x - 1] != c)
			return (-1);
		i++;
	}
	j = 0;
	while (j < sl->x)
	{
		if(sl->map_arr[0][j] != c || sl->map_arr[sl->y - 1][j] != c)
			return (-1);
		j++;
	}
	return 0;
}

int map_validation(l_list *sl)
{
	if(!sl->map_arr || !sl->map_arr[0])
		return (-1);
	if (map_check_rectangle(&sl) == -1)
		return (-1);
	if (map_check_enclosure(&sl) == -1)
		return (-1);
	if (map_check_chars(&sl) == -1)
		return (-1); 
	return (0);
}