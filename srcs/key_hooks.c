/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:33:01 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/19 18:35:52 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_keys(int keycode, t_win *win)
{
	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
		move_checker(win, keycode);
	if (keycode == 65307)
	{
		print_error("You closed the game.", 0);
	}
	return (0);
}

int	movement_keys(int keycode, t_win *win)
{
	char		*str;
	static int	i = 0;

	str = ft_itoa(++i);
	mlx_put_image_to_window(win->mlx, win->win, win->img[0], 0, 0);
	mlx_string_put(win->mlx, win->win, 10, 10, 0xFFFFFF, str);
	free(str);
	mlx_put_image_to_window(win->mlx, win->win, win->img[5], \
	win->ply_x, win->ply_y);
	win->ply_x += ((keycode == 100) - (keycode == 97)) * 48;
	win->ply_y += ((keycode == 115) - (keycode == 119)) * 48;
	mlx_put_image_to_window(win->mlx, win->win, win->img[(keycode == 119) + \
	(keycode == 115) * 2 + (keycode == 100) * 4 + \
	(keycode == 97) * 3], win->ply_x, win->ply_y);
	collect_check(win);
	return (0);
}

void	player_position(t_win *win)
{
	int	x;
	int	y;

	x = -1;
	while (win->map[++x])
	{
		y = -1;
		while (win->map[x][++y])
		{
			if (win->map[x][y] == 'P')
			{
			win->ply_x = y * 48;
			win->ply_y = x * 48;
			}
		}
	}
}

// int	render_sprite(t_win	*win)
// {
	
// }
