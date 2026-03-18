/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:56:57 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/18 13:16:32 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(char const *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_extract_rest(const char *s, int c);
char	*ft_extract_line(const char *s, int c);
char	*ft_getstring(int fd, char *stash, int fnd);
char	*ft_getstring_ext(char *stash, char *buf);
char	*get_next_line(size_t fd);

#endif
