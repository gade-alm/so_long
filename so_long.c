/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:33:00 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/17 11:14:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		print_error("Please write ./so_long [map name]", 1);
	format_checker(argv[1]);
	open_map(argv[1]);
	letter_counter(wincall());
	player_position(wincall());
	window_creator(wincall());
}
