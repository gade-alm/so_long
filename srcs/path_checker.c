/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:08 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/20 10:35:02 by gabrieldeal      ###   ########.fr       */
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
	if (copy[y - 1][x] == 'C' || copy[y - 1][x] == '0')
		check_path(copy, x, y - 1);
	if (copy[y][x + 1] == 'C' || copy[y][x + 1] == '0')
		check_path(copy, x + 1, y);
	if (copy[y][x - 1] == 'C' || copy[y][x - 1] == '0')
		check_path(copy, x - 1, y);
}

void	valid_path(char	**copy, int x, int y)
{
	char	**tmp;

	tmp = map_copy(copy);
	for (int i = 0; i < wincall()->win_y; i++)
		printf("%s\n",tmp[i]);
	check_path(tmp, wincall()->ply_x / 48, wincall()->ply_y / 48);
	for (int i = 0; i < wincall()->win_y; i++)
		printf("%s\n",tmp[i]);
	y = -1;
	while (tmp[++y])
	{
		x = -1;
		while (tmp[y][++x])
		{
			if (tmp[y][x] == 'C')
			{
				free_map(tmp);
				print_error("Check map path", 1);
			}
			if (tmp[y][x] == 'E' && (!(tmp[y + 1][x] == 'P' || \
			tmp[y - 1][x] == 'P' || tmp[y][x + 1] == 'P' || \
			tmp[y][x - 1] == 'P')))
			{
				free_map(tmp);
				print_error("Check map path", 1);
			}
		}
	}
	free_map(tmp);
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
