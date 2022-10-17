# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 16:54:55 by gade-alm          #+#    #+#              #
#    Updated: 2022/10/17 13:07:27 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= so_long.c \
		srcs/map_functions.c \
		srcs/libft.c	 \
		srcs/key_hooks.c \
		srcs/exit_game.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/map_functions_2.c \
		srcs/path_checker.c \

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

RM		= rm -rf

MLX		= mlx_linux/libmlx_Linux.a

PRINTF	= libs/ft_printf/libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(MLX) $(PRINTF) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -Llibs/ft_printf -l:libftprintf.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C mlx_linux

$(PRINTF):
	make -C libs/ft_printf

clean: 
	$(RM) $(OBJS)
	make clean -C mlx_linux
	make clean -C libs/ft_printf
	$(RM) a.out

fclean: clean
		$(RM) $(NAME) $(OBJS)
		make fclean -C libs/ft_printf

re: fclean all

.PHONY: all clean fclean re