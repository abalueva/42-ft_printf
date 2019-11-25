/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:18:04 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 16:39:54 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*str_f(t_specifier *sp, va_list args)
{
	char	*num;

	num = NULL;
	if (sp->length != 1 && sp->length % 5 == 0)
		num = ft_ftoa(sp, (long double)va_arg(args, long double));
	else
		num = ft_ftoa(sp, (double)va_arg(args, double));
	return (num);
}

static int		f_left(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;

	ret = 0;
	i = num[0] == '-' ? 0 : -1;
	handle_sign(num[0], sp->flags, &ret);
	print_input(num, len, &ret);
	i = ret - 1;
	while (++i < sp->width)
		printf_putchar(' ', &ret);
	return (ret);
}

static int		f_other(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;

	ret = 0;
	i = -1;
	if (num[0] == '-' ||
		check_flags(sp->flags, 3) != -1 || check_flags(sp->flags, 0) != -1)
		i = 0;
	if (check_flags(sp->flags, 2) != -1)
	{
		handle_sign(num[0], sp->flags, &ret);
		while (++i < sp->width - len)
			printf_putchar('0', &ret);
		print_input(num, len, &ret);
	}
	else
	{
		while (++i < sp->width - len)
			printf_putchar(' ', &ret);
		handle_sign(num[0], sp->flags, &ret);
		print_input(num, len, &ret);
	}
	return (ret);
}

int				print_f(t_specifier *sp, va_list args)
{
	int			ret;
	int			len;
	char		*num;
	int			flag;

	ret = 0;
	num = NULL;
	sp->precision = sp->precision == -1 ? 6 : sp->precision;
	num = str_f(sp, args);
	len = num[0] == '-' ? ft_strlen(num) - 1 : ft_strlen(num);
	flag = sp->precision == -1 ? 0 : 1;
	if (check_flags(sp->flags, 4) != -1)
		ret = f_left(sp, num, len);
	else
		ret = f_other(sp, num, len);
	return (ret);
}
