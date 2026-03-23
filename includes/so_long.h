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

typedef struct map {
    int         fd;
    int         x;
    int         y;
    char        *map;
    char        **map_arr;
	char		**map_dup;
}               m_list;

typedef struct unit {
	char		player;
	char		exit;
	char		collectible;
	char		wall;
	char		space;
}				u_list;

int		map_check_rectangle(m_list *sl);
int		map_check_chars(m_list *sl);
int		map_check_enclosure(m_list *sl, char c);
int		map_check_req_char(m_list *sl, u_list un, char c);
void	**map_dup(m_list *sl);
int		create_map(m_list *sl, u_list un, char **argv);
int		map_validation(m_list *sl, u_list un);
int		main(int argc, char **argv);

#endif