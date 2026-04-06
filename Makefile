# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 12:29:50 by mvelasqu          #+#    #+#              #
#    Updated: 2026/03/31 14:47:29 by mvelasqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Description

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -no-pie
RM			= rm -f

LIBDIR		= libft
LIBFLAGS	= $(LIBDIR)/libft.a

MLXDIR		= minilibx-linux
MLXFLAGS	= $(MLXDIR)/libmlx.a
MLX_LIBS	= -lXext -lX11 -lbsd -lm

INCDIR		= includes
INCFLAGS	= -I$(INCDIR) -I$(LIBDIR)/includes -I$(MLXDIR)

SRCS		= main.c \
				src/map_helper.c \
				src/map_init.c \
				src/map_create.c \
				src/map_duplicate.c \
				src/map_validation_1.c \
				src/map_validation_2.c \
				src/map_validation_3.c \
				src/game_helper.c \
				src/game_hooks.c \
				src/game_init.c \
				src/game_animate.c
OBJS		= $(SRCS:.c=.o)

#Commands
all: $(NAME)

$(NAME): $(LIBFLAGS) $(OBJS) $(LIBFLAGS) $(MLXFLAGS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBFLAGS) $(MLXFLAGS) $(MLX_LIBS) -o $(NAME)

$(LIBFLAGS):
	$(MAKE) -C $(LIBDIR)

$(MLXFLAGS):
	$(MAKE) -C $(MLXDIR)

%.o: %.c $(INCDIR)/so_long.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean:
	$(RM) $(NAME) $(OBJS)
	$(MAKE) -C $(LIBDIR) fclean


re:
	$(MAKE) fclean all

.PHONY: all fclean clean re