# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/18 12:29:50 by mvelasqu          #+#    #+#              #
#    Updated: 2026/04/10 10:10:47 by mvelasqu         ###   ########.fr        #
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
MLX_LIBS	= -lXext -lX11 -lbsd

INCDIR		= includes
INCFLAGS	= -I$(INCDIR) -I$(LIBDIR)/includes -I$(MLXDIR)

SRCS		= main.c \
				src/map_create.c \
				src/map_duplicate.c \
				src/map_helper.c \
				src/map_init.c \
				src/map_validate_format.c \
				src/map_validate_path.c \
				src/map_validation.c \
				src/game_animate.c \
				src/game_enemy.c \
				src/game_handle_move_key.c \
				src/game_helper.c \
				src/game_init.c \
				src/game_key_handle.c \
				src/game_print_move.c
SRCS_BONUS	= main.c \
				src/map_create.c \
				src/map_duplicate.c \
				src/map_helper.c \
				src/map_init.c \
				src/map_validate_format.c \
				src/map_validate_path.c \
				src/map_validation.c \
				src/game_animate.c \
				src/game_enemy.c \
				src/game_handle_move_key_bonus.c \
				src/game_helper.c \
				src/game_init.c \
				src/game_key_handle.c \
				src/game_print_move.c
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

#Commands
all: $(NAME)

bonus: $(LIBFLAGS) $(MLXFLAGS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LIBFLAGS) $(MLXFLAGS) $(MLX_LIBS) -o $(NAME)

$(NAME): $(LIBFLAGS) $(OBJS) $(MLXFLAGS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBFLAGS) $(MLXFLAGS) $(MLX_LIBS) -o $(NAME)

$(LIBFLAGS):
	$(MAKE) -C $(LIBDIR)

$(MLXFLAGS):
	$(MAKE) -C $(MLXDIR)

%.o: %.c $(INCDIR)/so_long.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re:
	$(MAKE) fclean all

.PHONY: all bonus fclean clean re