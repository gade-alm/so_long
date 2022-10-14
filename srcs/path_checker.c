/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:08 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/14 15:46:42 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_copy(t_win *win)
{
	char	**copy;
	int		i;

	i = -1;
	copy = malloc(sizeof(char *) * (win->win_y + 1));
	while (++i < win->win_y)
	{
		copy[i] = ft_strdup(win->map[i]);
		if (!copy[i])
			print_error("error on copy malloc", 1);
	}
	copy[i] = NULL;
	return (copy);
}

void	check_path(char **copy, int x, int y)
{
	t_win *win;

	win = wincall();
	copy[x][y] = 'P';
	if (copy[x + 1][y] == 'C' || copy[x + 1][y] == '0')
		check_path(copy, x + 1, y);
	if (copy[x - 1][y] == 'C' || copy[x - 1][y] == '0')
		check_path(copy, x - 1, y);
	if (copy[x][y + 1] == 'C' || copy[x][y + 1] == '0')
		check_path(copy, x, y + 1);
	if (copy[x][y - 1] == 'C' || copy[x][y - 1] == '0')
		check_path(copy, x, y - 1);
}

void	valid_path(char	**copy)
{
	char	**temp;

	temp = map_copy(copy);
	check_path(temp, win->ply_x / 48, win->ply_y / 48);
	
	if (temp)
		free (temp);
	
	
}