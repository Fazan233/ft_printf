/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:35:37 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/09 21:45:13 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MODE_FLAGS 5
# define CONVERSIONS "cspdiouxXfeg"
# define FLAGS "+- #0"
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>

typedef unsigned long long t_ull;
typedef long long t_ll;


typedef struct		s_format
{
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	sharp:1;
	unsigned int	zero:1;
	unsigned int	precision:1;
	unsigned int	size:1;
	int				s_val;
	int				type;
	int				w_val;
	int				p_val;
}					t_format;

int					find_flags(char *str, t_format *form);
void				flags(t_format *form, char **str);
int					size(t_format *form, char **str);
void				precision(t_format *form, char **str);
void				width(t_format *form, char **str);
int 				conversion(t_format *form, char **str);
size_t	f_c(t_format *form, va_list *ap, char **buf);
size_t	f_s(t_format *form, va_list *ap, char **str);
int					ft_printf(char *str, ...);
void	get_strwidth(t_format *form, void **str, int count);
void	cast_signed(long long int *n, va_list *ap, t_format *f);
void	cast_unsigned(unsigned long long int *n, va_list *ap, t_format *f);
size_t	number_format(char **nbr, t_format *f);
size_t	f_pdiouxX(t_format *f, va_list *ap, char **str);
size_t	get_format_number(t_format *f, void *n, char **str, int sig);
#endif
