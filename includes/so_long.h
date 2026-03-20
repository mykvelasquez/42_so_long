/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 12:30:37 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <error.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list {
    int         fd;
    int         x;
    int         y;
    char        *map;
    char        **map_arr;
	char		**map_dup;
}               l_list;

typedef struct s_list{
	char		player;
	char		exit;
	char		collectible;
	char		wall;
	char		space;
}				u_list;

int		map_check_rectangle(l_list *sl);
int		map_check_chars(l_list *sl);
int		map_check_enclosure(l_list *sl, char c);
int		map_check_req_char(l_list *sl, u_list un, char c);
void	**map_dup(l_list *sl);
int		create_map(l_list *sl, u_list un, char **argv);
int		map_validation(l_list *sl, u_list un);
int		main(int argc, char **argv);

#endif