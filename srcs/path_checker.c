/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:08 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/12 16:22:32 by gabrieldeal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_copy(t_win *win, int y)
{
	char	**copy;
	int		i;

	(void) y;
	i = -1;
	printf("x%i\ny%i\n", win->win_x, win->win_y);
	copy = malloc(sizeof(char *) * (win->win_y + 1));
	while (++i < win->win_y)
		copy[i] = ft_strdup(win->map[i]);
	copy[i] = NULL;
	check_path(copy, win->ply_x / 48, win->ply_y / 48);
	return (copy);
}

/* void	check_path(char **copy, int x, int y)
{
	t_win *win;
	
	win = wincall();

	if ((win->map[x + 1][y] == 'E' && win->c_num > 0 ) || win->map[x + 1][y] == '0')
	{
		check_path(copy, x + 1, y);
		win->map[x][y] = 'P';
	}
	if ((win->map[x - 1][y] == 'E' && win->c_num > 0 ) || win->map[x - 1][y] == '0')
	{
		check_path(copy, x - 1, y);
		win->map[x][y] = 'P';
	}
	if ((win->map[x][y + 1] == 'E' && win->c_num > 0 ) || win->map[x][y + 1] == '0')
	{
		check_path(copy, x, y + 1);
		win->map[x][y] = 'P';
	}
	if ((win->map[x][y - 1] == 'E' && win->c_num > 0 ) || win->map[x][y - 1] == '0')
	{
		check_path(copy,x, y - 1);
		win->map[x][y] = 'P';
	}
}