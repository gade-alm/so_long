/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:45:25 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/16 16:40:32 by gabrieldeal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/so_long.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	int				re;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{		
		re = 1;
		if (!buffer[0])
			re = read(fd, buffer, BUFFER_SIZE);
		if (re > 0)
			line = ft_get_line(buffer, line);
		if (re < 1 || is_newline(buffer))
			break ;
	}
	return (line);
}
