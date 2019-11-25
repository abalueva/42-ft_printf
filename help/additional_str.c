/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:21:23 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 19:50:13 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

void		printf_putchar(char c, int *ret)
{
	write(1, &c, 1);
	*ret = *ret + 1;
}

void		printf_putstr(char *str, int *ret)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		printf_putchar(str[i], ret);
}

void		printf_putstr_ox(char spec, int *ret)
{
	if (spec == 'x' || spec == 'p')
		printf_putstr("0x", ret);
	else if (spec == 'X')
		printf_putstr("0X", ret);
	else if (spec == 'o')
		printf_putstr("0", ret);
	else if (spec == 'b')
		printf_putstr("0b", ret);
}

void		ft_toupper_str(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

int			find_char(char c, char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (c == str[i])
			return (i);
	return (-1);
}
