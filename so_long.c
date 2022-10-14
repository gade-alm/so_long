/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-alm <gade-alm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:33:00 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/14 18:46:32 by gade-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (write(1, "error", 5));
	format_checker(argv[1]);
	open_map(argv[1]);
	letter_counter(wincall());
	player_position(wincall());
	printf("%i\n", (wincall()->map != NULL));
	window_creator(wincall());
}
