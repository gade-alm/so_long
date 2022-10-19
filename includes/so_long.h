/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:34:12 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/19 16:28:35 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_win{
	void	**img;
	void	*mlx;
	void	*win;
	char	**map;
	int		win_x;
	int		win_y;
	int		x;
	int		y;
	int		ply_x;
	int		ply_y;
	int		e_num;
	int		p_num;
	int		c_num;
}		t_win;

/*Keycode:
W = 119
A = 97
S = 115 
D = 100
ESC = 65307
*/

//Window, maps and images functions
int		button_exit(void);
void	check_path(char **copy, int x, int y);
void	collect_check(t_win	*win);
int		format_checker(char *str);
void	free_map(char	**map);
int		letter_checker(char *map);
int		letter_counter(t_win *win);
char	**map_copy(char	**copy);
char	**map_to_str(char **map, int fd, int i);
void	open_map(char *map);
void	print_error(char *str, int i);
void	put_image(t_win	*win);
void	player_position(t_win *win);
void	valid_path(char	**copy, int x, int y);
void	window_creator(t_win *win);

//Input functions
int		close_keys(int keycode, t_win *win);
int		exit_game(t_win *win);
int		move_checker(t_win *win, int keycode);
int		movement_keys(int keycode, t_win *win);

//Utility functions
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_itoa(int n);
t_win	*wincall(void);

#endif
