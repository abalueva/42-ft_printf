/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upxxob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:43:08 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 20:43:13 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pxxob_hash(t_specifier *sp, int len)
{
	if (sp->specifier != 'o' && check_flags(sp->flags, 1) > 0)
		return (2);
	if (sp->specifier == 'o' && check_flags(sp->flags, 1) > 0 &&
		sp->precision <= len)
		return (1);
	return (0);
}

static int		upxxob_left(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;
	int hash;

	ret = 0;
	hash = pxxob_hash(sp, len);
	if (check_flags(sp->flags, 1) != -1)
		printf_putstr_ox(sp->specifier, &ret);
	i = ret > 0 && sp->specifier == 'o' ? 0 : -1;
	while (++i < sp->precision - len)
		printf_putchar('0', &ret);
	print_input(num, sp->precision, &ret);
	i = ret - 1;
	while (++i < sp->width)
		printf_putchar(' ', &ret);
	return (ret);
}

static int		upxxob_zero(t_specifier *sp, char *num, int len, int flag)
{
	int		i;
	int		ret;
	int		hash;

	i = -1;
	ret = 0;
	hash = pxxob_hash(sp, len);
	if (sp->width > sp->precision && flag)
		while (++i < sp->width - sp->precision - hash)
			printf_putchar(' ', &ret);
	check_flags(sp->flags, 1) > 0 ? printf_putstr_ox(sp->specifier, &ret) : 0;
	if (flag)
	{
		i = sp->specifier == 'o' && check_flags(sp->flags, 1) > 0 ? 0 : -1;
		while (++i < sp->precision && i < sp->precision - len)
			printf_putchar('0', &ret);
	}
	else
		while (++i < sp->width - sp->precision - hash)
			printf_putchar('0', &ret);
	print_input(num, sp->precision, &ret);
	return (ret);
}

static int		upxxob_other(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;
	int hash;

	ret = 0;
	i = -1;
	hash = pxxob_hash(sp, len);
	while (++i < sp->width - sp->precision - hash)
		printf_putchar(' ', &ret);
	if (check_flags(sp->flags, 1) != -1)
		printf_putstr_ox(sp->specifier, &ret);
	i = sp->specifier == 'o' && check_flags(sp->flags, 1) > 0 ? 0 : -1;
	while (++i < sp->precision - len)
		printf_putchar('0', &ret);
	print_input(num, sp->precision, &ret);
	return (ret);
}

int				print_upxxob(t_specifier *sp, va_list args)
{
	int			ret;
	int			len;
	char		*num;
	int			flag;

	ret = 0;
	num = str_upxxob(sp->length, args, sp->specifier);
	if (check_flags(sp->flags, 1) != -1 && num[0] == '0')
		if (!(sp->precision == 0 && sp->specifier == 'o'))
			sp->flags -= ft_power(2, 1);
	num = (num[0] == '0' && sp->precision == 0) ? "" : num;
	len = ft_strlen(num);
	flag = sp->precision == -1 ? 0 : 1;
	sp->precision = sp->precision < len ? len : sp->precision;
	sp->flags = sp->specifier == 'p' ? sp->flags + ft_power(2, 1) : sp->flags;
	if (check_flags(sp->flags, 4) != -1)
		ret = upxxob_left(sp, num, len);
	else
		ret = check_flags(sp->flags, 2) > 0 ? upxxob_zero(sp, num, len, flag) :
												upxxob_other(sp, num, len);
	return (ret);
}
