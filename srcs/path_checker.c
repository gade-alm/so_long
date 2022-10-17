/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:08 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/17 11:18:12 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_copy(char	**copy)
{
	t_win	*win;
	char	**temp;
	int		i;

	win = wincall();
	temp = malloc(sizeof(char *) * (win->win_y + 1));
	if (!temp)
		print_error("Can't allocate copy", 1);
	i = -1;
	while (++i < win->win_y)
	{
		temp[i] = ft_strdup(copy[i]);
		if (!temp[i])
			print_error("Error on copy malloc", 1);
	}
	temp[i] = NULL;
	return (temp);
}

void	check_path(char **copy, int x, int y)
{
	copy[y][x] = 'P';
	if (copy[y + 1][x] == 'C' || copy[y + 1][x] == '0')
		check_path(copy, x, y + 1);
	if (y > 0 && (copy[y - 1][x] == 'C' || copy[y - 1][x] == '0'))
		check_path(copy, x, y - 1);
	if (copy[y][x + 1] == 'C' || copy[y][x + 1] == '0')
		check_path(copy, x + 1, y);
	if (copy[y][x - 1] == 'C' || copy[y][x - 1] == '0')
		check_path(copy, x - 1, y);
}

void	valid_path(char	**copy)
{
	char	**temp;
	int		x;
	int		y;

	temp = map_copy(copy);
	check_path(temp, wincall()->ply_x / 48, wincall()->ply_y / 48);
	y = -1;
	while (temp[++y])
	{
		x = -1;
		while (temp[y][++x])
		{
			if (temp[y][x] == 'C')
			{
				free_map(temp);
				print_error("rever", 1);
			}
			if (temp[y][x] == 'E' && (temp[y + 1][x] == 'P' || \
			temp[y - 1][x] == 'P' || temp[y][x + 1] == 'P' || temp[y][x - 1] == 'P'))
			{
				free_map(temp);
				return ;
			}
		}
	}
}

void	free_map(char	**map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free (map[i++]);
		free(map);
	}
}