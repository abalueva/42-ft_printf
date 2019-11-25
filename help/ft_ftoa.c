/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:08:21 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 20:52:53 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

static char				*ftoa_zeroes(long double n, int sp_precision)
{
	int			i;
	int			j;
	char		*zero;
	double long	fraction;

	fraction = n > 0 ? (n - (long long)n) : ((long long)n - n);
	i = 0;
	while (fraction <= 0.9 && sp_precision > 0)
	{
		if ((fraction * 10) >= 9.999999999)
			break ;
		i++;
		sp_precision--;
		fraction = fraction * 10;
	}
	i = i > 0 ? i - 1 : i;
	zero = (char *)malloc(sizeof(char) * i);
	j = -1;
	while (++j < i)
		zero[j] = '0';
	zero[j] = '\0';
	return (zero);
}

static long long		ftoa_fraction(long double n, int sp_precision)
{
	double long	fraction;

	fraction = n > 0 ? (n - (long long)n) : ((long long)n - n);
	while (sp_precision > 6)
	{
		fraction = fraction * ft_power(10, 6);
		sp_precision -= 6;
	}
	fraction = fraction * ft_power(10, sp_precision) + 0.5;
	return ((unsigned long long)fraction);
}

static char				*ftoa_make_int(t_specifier *sp, long double n)
{
	char	*str_integer;

	if (n < 0 && (long long)n == 0)
	{
		str_integer = (char *)malloc(sizeof(char) * 2);
		str_integer[0] = '-';
		str_integer[1] = '0';
	}
	else if (sp->precision == 0)
	{
		n = n > 0 ? n + 0.5 : n - 0.5;
		str_integer = ft_itoa((long long)n);
		if (check_flags(sp->flags, 1) == 1)
			return (ft_strcat(str_integer, "."));
		else
			return (str_integer);
	}
	else
		str_integer = ft_itoa((long long)n);
	return (str_integer);
}

char					*ft_ftoa(t_specifier *sp, long double n)
{
	long long	fraction;
	char		*zeroes;
	char		*str_integer;
	char		*str_fraction;

	str_integer = NULL;
	str_fraction = NULL;
	zeroes = NULL;
	str_integer = ftoa_make_int(sp, n);
	if (sp->precision > 0)
	{
		fraction = ftoa_fraction(n, sp->precision);
		zeroes = ftoa_zeroes(n, sp->precision);
		ft_strcat(str_integer, ".");
		ft_strcat(str_integer, zeroes);
		str_fraction = ft_itoa(fraction);
		ft_strcat(str_integer, str_fraction);
	}
	return (str_integer);
}
