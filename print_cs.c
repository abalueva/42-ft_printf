/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:07:29 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/21 23:34:14 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_c(t_specifier *sp, va_list args)
{
	int		ret;
	char	c;

	ret = 0;
	c = sp->specifier == '%' ? '%' : (char)va_arg(args, int);
	if (check_flags(sp->flags, 4) != -1)
		printf_putchar(c, &ret);
	while (--sp->width > 0)
		if (check_flags(sp->flags, 2) != -1 &&
			check_flags(sp->flags, 4) == -1)
			printf_putchar('0', &ret);
		else
			printf_putchar(' ', &ret);
	if (check_flags(sp->flags, 4) == -1)
		printf_putchar(c, &ret);
	return (ret);
}

static int		s_left(t_specifier *sp, char *str, int len)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < sp->precision && i < len)
		printf_putchar(str[i], &ret);
	i--;
	while (++i < sp->width)
		printf_putchar(' ', &ret);
	return (ret);
}

static int		s_other(t_specifier *sp, char *str, int len)
{
	int i;
	int ret;

	i = -1;
	ret = 0;
	while (++i < sp->width - sp->precision || i < sp->width - len)
		check_flags(sp->flags, 2) > 0 ? printf_putchar('0', &ret) :
										printf_putchar(' ', &ret);
	i = -1;
	while (++i < sp->precision && i < len)
		printf_putchar(str[i], &ret);
	return (ret);
}

int				print_s(t_specifier *sp, va_list args)
{
	int		len;
	char	*str;
	int		ret;

	if (!(str = (char *)va_arg(args, char*)))
		str = "(null)";
	ret = 0;
	len = ft_strlen(str);
	sp->precision = sp->precision == -1 ? len : sp->precision;
	ret = check_flags(sp->flags, 4) != -1 ? s_left(sp, str, len) :
											s_other(sp, str, len);
	return (ret);
}
