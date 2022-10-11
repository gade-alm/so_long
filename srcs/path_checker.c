/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:08 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/11 13:42:34 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	path_checker(t_win *win, int x, int y)
{
	x = win->ply_x / 48;
	y = win->ply_y / 48;
	
	win->map[y][x] = 'P';
	if ((win->map[x + 1][y] == 'E' && win->c_num > 0 ) || win->map[x + 1][y] == '0')
		path_checker(win, x + 1, y);
	else if ((win->map[x - 1][y] == 'E' && win->c_num > 0 ) || win->map[x - 1][y] == '0')
		path_checker(win, x - 1, y);
	return (1);
}
