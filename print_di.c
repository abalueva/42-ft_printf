/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:39:34 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:14:57 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		di_left(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;

	ret = 0;
	i = num[0] == '-' ? 0 : -1;
	handle_sign(num[0], sp->flags, &ret);
	len = num[0] == '-' ? len - 1 : len;
	while (++i < sp->precision - len && num[0] != '\0')
		printf_putchar('0', &ret);
	i = num[0] == '-' ? 0 : -1;
	while (++i < sp->precision + 1 && num[i] != '\0')
		printf_putchar(num[i], &ret);
	i = ret - 1;
	while (++i < sp->width)
		printf_putchar(' ', &ret);
	return (ret);
}

static int		di_zero(t_specifier *sp, char *num, int len, int flag)
{
	int i;
	int ret;

	ret = 0;
	i = num[0] == '-' ? 0 : -1;
	i = num[0] != '-' &&
		(check_flags(sp->flags, 3) != -1 || check_flags(sp->flags, 0) != -1)
		? i + 1 : i;
	if (sp->width > sp->precision && flag)
		while (++i < sp->width - sp->precision)
			printf_putchar(' ', &ret);
	handle_sign(num[0], sp->flags, &ret);
	if (flag)
	{
		i = 0;
		while (++i < sp->precision && i < sp->precision - len + 1)
			printf_putchar('0', &ret);
	}
	else
		while (++i < sp->width && i < sp->width - len && num[0] != '\0')
			printf_putchar('0', &ret);
	i = num[0] == '-' ? 0 : -1;
	while (++i < sp->precision + 1 && num[i] != '\0')
		printf_putchar(num[i], &ret);
	return (ret);
}

static int		di_other(t_specifier *sp, char *num, int len)
{
	int i;
	int ret;

	ret = 0;
	i = num[0] == '-' || check_flags(sp->flags, 3) != -1 ||
							check_flags(sp->flags, 0) != -1 ?
				0 : -1;
	while (++i < sp->width - sp->precision)
		printf_putchar(' ', &ret);
	handle_sign(num[0], sp->flags, &ret);
	i = -1;
	while (++i < sp->precision - len)
		printf_putchar('0', &ret);
	print_input(num, sp->precision, &ret);
	return (ret);
}

int				print_di(t_specifier *sp, va_list args)
{
	int			ret;
	int			len;
	char		*num;
	int			flag;

	ret = 0;
	num = str_di(sp->length, args);
	num = (num[0] == '0' && sp->precision == 0) ? "" : num;
	len = num[0] == '-' ? ft_strlen(num) - 1 : ft_strlen(num);
	flag = sp->precision == -1 ? 0 : 1;
	sp->precision = sp->precision < len ? len : sp->precision;
	if (check_flags(sp->flags, 4) != -1)
		ret = di_left(sp, num, len);
	else
	{
		if (check_flags(sp->flags, 2) != -1)
			ret = di_zero(sp, num, len, flag);
		else
			ret = di_other(sp, num, len);
	}
	return (ret);
}
