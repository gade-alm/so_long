/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:30:45 by gade-alm          #+#    #+#             */
/*   Updated: 2022/09/10 12:42:03 by gabrieldeal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlennl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break;
		;
	return (i);
}

int	is_newline(char *str)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	j = 0;
	while (str[i])
	{
		if (ret)
			str[j++] = str[i];
		if (str[i] == '\n')
			ret = 1;
		str[i] = 0;
		i++;
	}
	return (ret);
}

char	*ft_get_line(char *buff, char *line)
{
	int		i;
	int		j;
	int		buff_size;
	char	*temp;

	buff_size = ft_strlennl(buff);
	temp = malloc(sizeof(char) * (buff_size + ft_strlennl(line) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		temp[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buff_size)
		temp[i++] = buff[j++];
	temp[i] = '\0';
	if (line)
		free (line);
	return (temp);
}
