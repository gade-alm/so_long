/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:56:47 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/11 22:25:30 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	letter_counter(t_win	*win)
{
	int	x;
	int	y;

	x = -1;
	while (win->map[++x])
	{
		y = -1;
		while (win->map[x][++y])
		{
			if (win->map[x][y] == 'E')
				win->e_num++;
			if (win->map[x][y] == 'P')
				win->p_num++;
			if (win->map[x][y] == 'C')
				win->c_num++;
		}
		if (y != win->win_x)
			print_error("Not rectangular", 1);
	}
	if (win->e_num != 1 || win->p_num != 1 || win->c_num < 1)
		print_error("Wrong number of characters", 1);
	return (0);
}

static void	load_images(t_win	*win)
{
	int	i;
	int	j;

	i = 48;
	j = i;
	win->img = malloc(9 * sizeof(void *));
	if (!win->img)
		exit_game(wincall());
	win->img[0] = mlx_xpm_file_to_image(win->mlx, "imgs/wall.xpm", &i, &j);
	win->img[1] = mlx_xpm_file_to_image(win->mlx, "imgs/mushup.xpm", &i, &j);
	win->img[2] = mlx_xpm_file_to_image(win->mlx, "imgs/mushdown.xpm", &i, &j);
	win->img[3] = mlx_xpm_file_to_image(win->mlx, "imgs/mushleft.xpm", &i, &j);
	win->img[4] = mlx_xpm_file_to_image(win->mlx, "imgs/mush.xpm", &i, &j);
	win->img[5] = mlx_xpm_file_to_image(win->mlx, "imgs/floor.xpm", &i, &j);
	win->img[6] = mlx_xpm_file_to_image(win->mlx, "imgs/cat.xpm", &i, &j);
	win->img[7] = mlx_xpm_file_to_image(win->mlx, "imgs/c_exit.xpm", &i, &j);
	win->img[8] = mlx_xpm_file_to_image(win->mlx, "imgs/c_exit.xpm", &i, &j);
}

void	put_image(t_win	*win)
{
	int	x;
	int	y;

	x = -1;
	load_images(win);
	while (win->map[++x])
	{
		y = -1;
		while (win->map[x][++y])
		{
			mlx_put_image_to_window(win->mlx, win->win, \
			win->img[(win->map[x][y] == 'P') * 4 + \
			(win->map[x][y] == '0') * 5 + (win->map[x][y] == 'C') * 6 \
			+ (win->map[x][y] == 'E') * 7] \
			, y * 48, x * 48);
		}
	}
}

int	move_checker(t_win *win, int keycode)
{
	int	x;
	int	y;

	x = win->ply_y / 48;
	y = win->ply_x / 48;
	if (keycode == 97 && win->map[x][y - 1] != '1' && \
	(win->map[x][y - 1] != 'E' || !win->c_num))
		movement_keys(keycode, win);
	else if (keycode == 100 && win->map[x][y + 1] != '1' && \
	(win->map[x][y + 1] != 'E' || !win->c_num))
		movement_keys(keycode, win);
	else if (keycode == 119 && win->map[x - 1][y] != '1' && \
	(win->map[x - 1][y] != 'E' || !win->c_num))
		movement_keys(keycode, win);
	else if (keycode == 115 && win->map[x + 1][y] != '1' && \
	(win->map[x + 1][y] != 'E' || !win->c_num))
		movement_keys(keycode, win);
	return (0);
}

void	collect_check(t_win	*win)
{
	int	x;
	int	y;

	x = win->ply_y / 48;
	y = win->ply_x / 48;
	if (win->map[x][y] == 'C')
	{
			win->map[x][y] = '0';
			win->c_num--;
		printf("%i\n", win->c_num);
	}
	if (win->map[x][y] == 'E' && win->c_num == 0)
		print_error("You win! :)", 0);
}
