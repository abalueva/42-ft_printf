/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:59:55 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 16:43:35 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			sp_init(t_specifier *sp, char specifier)
{
	sp->specifier = specifier;
	sp->flags = 0;
	sp->width = 0;
	sp->precision = -1;
	sp->length = 1;
}

static int		do_bonus(t_specifier *sp, va_list args, int wp)
{
	int k;

	k = (int)va_arg(args, int);
	if (k < 0)
	{
		if (wp)
		{
			sp->width = -k;
			sp->flags += ft_power(2, 4);
		}
		else
			sp->precision = -1;
		return (1);
	}
	if (wp)
		sp->width = k;
	else
		sp->precision = k;
	return (1);
}

static int		sp_load_numbers(int *num, char *sp_str, int i)
{
	int j;

	j = i - 1;
	while (sp_str[++j] >= 48 && sp_str[j] <= 57)
		*num = *num * 10 + (sp_str[j] - 48);
	*num = ft_atoi(ft_strsub(sp_str, i, j));
	return (j - 1);
}

static void		sp_load_length(t_specifier *sp, char sp_str)
{
	if (sp_str == 'h')
		sp->length *= 2;
	else if (sp_str == 'l')
		sp->length *= 3;
	else if (sp_str == 'L')
		sp->length *= 5;
}

int				sp_load(char *sp_str, t_specifier *sp, va_list args)
{
	int i;
	int k;

	i = 0;
	while (sp_str[i] != '\0')
	{
		i = sp_str[i] == '*' ? i + do_bonus(sp, args, 1) : i;
		if (((k = find_char(sp_str[i], FLAGS)) >= 0) &&
			(check_flags(sp->flags, k) == -1))
			sp->flags += ft_power(2, k);
		i = sp_str[i] >= 49 && sp_str[i] <= 57 ?
			sp_load_numbers(&(sp->width), sp_str, i) : i;
		sp->precision = sp_str[i] == '.' ? 0 : sp->precision;
		if (sp_str[i] == '.')
			i = sp_str[i + 1] == '*' ? i + do_bonus(sp, args, 0) :
							sp_load_numbers(&(sp->precision), sp_str, i + 1);
		find_char(sp_str[i], LENGTH) >= 0 ? sp_load_length(sp, sp_str[i]) : 0;
		i++;
	}
	sp->flags = check_flags(sp->flags, 0) >= 0 && check_flags(sp->flags, 3) >= 0
				? sp->flags - ft_power(2, 0) : sp->flags;
	sp->flags = check_flags(sp->flags, 2) >= 0 && check_flags(sp->flags, 4) >= 0
				? sp->flags - ft_power(2, 2) : sp->flags;
	return (0);
}
