/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:06:38 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/19 18:08:30 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_to_str(char **map, int fd, int i)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
	{
		wincall()->win_y++;
		letter_checker(str);
		map = map_to_str(map, fd, i + 1);
	}
	if (!map)
		map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		exit_game(wincall()->win);
	map[i] = str;
	return (map);
}

void	open_map(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		print_error("It's a directory type", 1);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error("Check name of the map", 1);
	(wincall())->map = map_to_str(NULL, fd, 0);
}

int	format_checker(char *str)
{	
	if (!ft_strncmp(ft_strrchr(str, '.'), ".ber", 5))
		return (1);
	print_error("Check format of the map", 1);
	return (0);
}

int	letter_checker(char *map)
{
	int	i;
	int	j;

	j = ft_strlen(map) - 1;
	i = -1;
	if (map[0] != '1' || map[j] != '1')
		print_error("Border error", 1);
	while (map[++i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'P' && map[i] != 'C' \
		&& map[i] != 'E' && map[i] != 'X')
			print_error("Wrong letter on the map", 1);
	}
	return (0);
}

void	window_creator(t_win *win)
{
	valid_path(win->map, 0, 0);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->win_x * 48, \
	win->win_y * 48, "My Game");
	put_image(wincall());
	mlx_hook(win->win, 02, (1L << 0), close_keys, win);
	mlx_hook(win->win, 17, (1L << 2), button_exit, win);
	mlx_loop(win->mlx);
}
