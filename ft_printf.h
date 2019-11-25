/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:27:04 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:07:18 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "help/help.h"

void			sp_init(t_specifier *sp, char specifier);
int				sp_load(char *sp_str, t_specifier *sp, va_list args);

char			*str_upxxob(int sp_length, va_list args, char spec);
char			*str_u(int sp_length, va_list args);
char			*str_di(int sp_length, va_list args);

int				print_c(t_specifier *sp, va_list args);
int				print_s(t_specifier *sp, va_list args);
int				print_di(t_specifier *sp, va_list args);
int				print_upxxob(t_specifier *sp, va_list args);
int				print_f(t_specifier *sp, va_list args);

int				ft_printf(const char *format, ...);

#endif
