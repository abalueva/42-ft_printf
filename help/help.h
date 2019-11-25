/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalueva <abalueva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:27:04 by abalueva          #+#    #+#             */
/*   Updated: 2019/11/24 21:02:36 by abalueva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_H
# define HELP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define SPECIFIERS "%cpsdixXoufb"
# define FLAGS " #0+-"
# define LENGTH "hlL"

typedef struct	s_specifier
{
	char	specifier;
	int		flags;
	int		width;
	int		precision;
	int		length;
}				t_specifier;

int				ft_atoi(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

void			printf_putchar(char c, int *ret);
void			printf_putstr(char *str, int *ret);
void			printf_putstr_ox(char spec, int *ret);
void			ft_toupper_str(char *str);
int				find_char(char c, char *str);

int				ft_power(int nb, int power);
int				check_flags(int flags, int k);
void			handle_sign(char sign, int sp_flags, int *ret);
void			print_input(char *str, int sp_precision, int *ret);
char			*ft_strcat(char *dest, char *src);

char			*ft_itoa(long long n);
char			*ft_itoa_base(unsigned long long n, int base);
char			*ft_ftoa(t_specifier *sp, long double n);

#endif
