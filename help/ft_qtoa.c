/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 23:06:27 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:04:59 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

char		*ft_itoa(long long n)
{
	int			len;
	char		*str;
	int			flag;
	long long	nb;

	flag = n >= 0 ? 0 : 1;
	len = n >= 0 ? 0 : 1;
	nb = n;
	while ((nb = nb / 10) != 0)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		if (len == 0 && flag)
			str[len] = '-';
		else
			str[len] = n > 0 ? n % 10 + 48 : (n % 10) * (-1) + 48;
		n /= 10;
		len--;
	}
	return (str);
}

char		*ft_itoa_base(unsigned long long n, int base)
{
	int					len;
	char				*str;
	unsigned long long	nb;

	len = 0;
	nb = n;
	while ((nb = nb / 10) != 0)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len + 1] = '\0';
	nb = n;
	if (nb == 0)
		return (str = "0");
	while (nb != 0)
	{
		if (base == 16)
			str[len] = nb % base < 10 ? nb % base + 48 : nb % base + 87;
		else
			str[len] = nb % base + 48;
		nb /= base;
		len--;
	}
	return (&str[len + 1]);
}
