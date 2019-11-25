/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:50:36 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 20:52:43 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sp_choose(t_specifier *sp, va_list args)
{
	int k;
	int	ret;
	int (*pointers[12])(t_specifier *, va_list);

	pointers[0] = print_c;
	pointers[1] = print_c;
	pointers[2] = print_upxxob;
	pointers[3] = print_s;
	pointers[4] = print_di;
	pointers[5] = print_di;
	pointers[6] = print_upxxob;
	pointers[7] = print_upxxob;
	pointers[8] = print_upxxob;
	pointers[9] = print_upxxob;
	pointers[10] = print_f;
	pointers[11] = print_upxxob;
	k = find_char(sp->specifier, SPECIFIERS);
	ret = pointers[k](sp, args);
	return (ret);
}

static int		vld_find_specifier(const char *format, int i)
{
	while (format[i] != '\0' && find_char(format[i], SPECIFIERS) < 0)
		i++;
	return (i);
}

static int		validation(const char *format, va_list args)
{
	int			i;
	int			j;
	int			ret;
	char		*sp_str;
	t_specifier *sp;

	i = 0;
	ret = 0;
	sp = malloc(sizeof(t_specifier));
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((j = vld_find_specifier(format, ++i)) && format[j] == 0)
				break ;
			sp_str = ft_strsub(format, i, j - i);
			sp_init(sp, format[j]);
			sp_load(sp_str, sp, args);
			ret += sp_choose(sp, args);
			i = j + 1;
		}
		else
			printf_putchar(format[i++], &ret);
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;

	va_start(args, format);
	ret = validation(format, args);
	return (ret);
}
