/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrieldealmeidatorres <gabrieldealmeid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:20:40 by gade-alm          #+#    #+#             */
/*   Updated: 2022/10/12 15:36:41 by gabrieldeal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != 0)
		;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *)s;
	while (str[len])
		len++;
	while (len >= 0)
	{
		if (str[len] == (unsigned char) c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	while ((s1[a] != 0) && (s2 != 0) && (s1[a] == s2[a]) && (a < n - 1))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		i;

	i = 0;
	nbr = n;
	if (n == 0)
		str = "0";
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	nbr = n;
	str[i--] = '\0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		a;
	int		len;

	a = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!ptr)
		return (NULL);
	while (a < len)
	{
		ptr[a] = s1[a];
		a++;
	}
	ptr[a] = '\0';
	return (ptr);
}
