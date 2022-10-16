/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:06:38 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/16 16:44:18 by gabrieldeal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//This function gnl the file than transfers it to my map, so I can read it in
//other functions and initalize the map sprites.
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

	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit_game(wincall());
	(wincall())->map = map_to_str(NULL, fd, 0);
}

//This function checks the if the format of the file is .ber so it is a valid
//map used in this project ****(TALVEZ MUDAR DE LOCAL)***
int	format_checker(char *str)
{	
	if (!ft_strncmp(ft_strrchr(str, '.'), ".ber", 5))
		return (1);
	printf("Check map format!");
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
		&& map[i] != 'E')
			print_error("Wrong letter on the map", 1);
	}
	return (0);
}

void	window_creator(t_win *win)
{
	valid_path(win->map);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->win_x * 48, \
	win->win_y * 48, "My Game");
	put_image(wincall());
	mlx_hook(win->win, 02, (1L << 0), close_keys, win);
	mlx_hook(win->win, 17, (1L << 2), exit_game, win);
	mlx_loop(win->mlx);
}
