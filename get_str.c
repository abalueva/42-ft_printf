/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:18:45 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:04:07 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*str_uxxob(int l, va_list args, int base)
{
	char	*num;

	if (l != 1 && l % 3 == 0)
	{
		l /= 3;
		num = (l % 3 == 0) ?
		ft_itoa_base((unsigned long long)va_arg(args, unsigned long long), base)
		: ft_itoa_base((unsigned long)va_arg(args, unsigned long), base);
	}
	else if (l != 1 && l % 2 == 0)
	{
		l /= 2;
		num = (l % 2 == 0) ?
			ft_itoa_base((unsigned char)va_arg(args, int), base) :
			ft_itoa_base((unsigned short int)va_arg(args, int), base);
	}
	else
		num = ft_itoa_base((unsigned int)va_arg(args, unsigned int), base);
	return (num);
}

char		*str_upxxob(int sp_length, va_list args, char spec)
{
	int		base;
	char	*num;
	char	*ptr;

	base = spec == 'p' || spec == 'x' || spec == 'X' ? 16 : 8;
	base = spec == 'b' ? 2 : base;
	base = spec == 'u' ? 10 : base;
	if (spec == 'p')
	{
		ptr = (void *)va_arg(args, void*);
		num = ptr == 0 ? "0" : ft_itoa_base((unsigned long long)ptr, 16);
	}
	else
		num = str_uxxob(sp_length, args, base);
	spec == 'X' ? ft_toupper_str(num) : 0;
	return (num);
}

char		*str_di(int sp_length, va_list args)
{
	char	*num;

	num = NULL;
	if (sp_length != 1 && sp_length % 3 == 0)
	{
		sp_length /= 3;
		num = (sp_length % 3 == 0) ?
			ft_itoa((long long)va_arg(args, long long)) :
			ft_itoa((long long)va_arg(args, long long));
	}
	else if (sp_length != 1 && sp_length % 2 == 0)
	{
		sp_length /= 2;
		num = (sp_length % 2 == 0) ?
			ft_itoa((signed char)va_arg(args, int)) :
			ft_itoa((short int)va_arg(args, int));
	}
	else
		num = ft_itoa((int)va_arg(args, int));
	return (num);
}
