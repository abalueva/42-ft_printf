/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:29:58 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:17:03 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "help.h"

int			ft_power(int nb, int power)
{
	if (nb == 0 || power < 0 || power > 30)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_power(nb, power - 1));
}

int			check_flags(int flags, int k)
{
	if ((flags & ft_power(2, k)) == ft_power(2, k))
		return (k);
	return (-1);
}

void		handle_sign(char sign, int sp_flags, int *ret)
{
	if (sign == '-')
		printf_putchar('-', ret);
	else if (check_flags(sp_flags, 3) != -1)
		printf_putchar('+', ret);
	else if (check_flags(sp_flags, 0) != -1)
		printf_putchar(' ', ret);
}

void		print_input(char *str, int sp_precision, int *ret)
{
	int i;

	i = str[0] == '-' ? 0 : -1;
	while (++i < sp_precision + 1 && str[i] != '\0')
		printf_putchar(str[i], ret);
}
