/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:02:19 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:17:06 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

int			ft_atoi(char *str)
{
	long	prev;
	long	nb;
	int		negative;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	negative = 1;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		prev = nb;
		nb = nb * 10 + (*str++ - '0');
		if (prev > nb)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
	}
	return ((int)(nb * negative));
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (!len)
	{
		str = "";
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
