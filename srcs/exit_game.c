/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:38:04 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/19 18:34:18 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *str, int i)
{
	if (!i)
		ft_printf("%s\n", str);
	else
		ft_printf("Error\n%s\n", str);
	exit_game(wincall());
}

int	button_exit(void)
{
	print_error("You closed the game.", 0);
	return (0);
}

int	exit_game(t_win *win)
{
	int	i;

	i = 0;
	if (win->map)
	{
		while (win->map[i])
			free (win->map[i++]);
		free(win->map);
	}
	i = 0;
	if (win->img)
	{	
		while (i < 11)
			mlx_destroy_image(win->mlx, win->img[i++]);
		free(win->img);
	}
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit (0);
}

t_win	*wincall(void)
{
	static t_win	win;

	return (&win);
}
