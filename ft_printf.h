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
# define CONVERSIONS "cspdiouxXfeEgG"
# define FLAGS "+- #0"
# define ABS(n) ((n) > 0) ? (n) : (n * -1)
# define MANTISS_LEN 64

# define STD		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define GRAY		"\033[37m"
# define EOC		"\033[0m"

# define BGSTD		"\033[40m"
# define BGRED		"\033[41m"
# define BGGREEN	"\033[42m"
# define BGYELLOW	"\033[43m"
# define BGBLUE		"\033[44m"
# define BGPURPLE	"\033[45m"
# define BGCYAN		"\033[46m"
# define BGGRAY		"\033[47m"

# define NORMAL		"\033[0m"
# define BOLD		"\033[1m"
# define DBOLD		"\033[2m"
# define NBOLD		"\033[22m"
# define UNDERLINE	"\033[4m"
# define BLINK		"\033[5m"
# define INVERSE	"\033[7m"


# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>

enum	e_conv{C, S, P, D, I, O, U, X, UPP_X, F, E, UPP_E, G, UPP_G};
typedef unsigned long long t_ull;
typedef long long t_ll;


typedef struct		s_format
{
	unsigned int	sign:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	sharp:1;
	unsigned int	zero:1;
	unsigned int	precision:1;
	unsigned int	size:1;
	int				s_val;
	enum e_conv		type;
	int				w_val;
	int				p_val;
}					t_format;

typedef struct		s_myfloat
{
	unsigned int 	exp_sign:1;
	unsigned int 	s:1;
	int 			e;
	t_ull			m;
	char 			*intnum;
	char 			*decimal;
	int 			len_i;
	int 			len_d;
	int 			exp_count;
}					t_myfloat;

typedef struct		s_pf
{
	va_list			ap;
	t_format 		form;
	void			*form_str;
	void 			*buf;
	size_t 			len_buf;
	int				len;
	int 			i;
	char 			*tmp;
}					t_pf;


int					find_flags(char **str, t_format *form, va_list *ap);
void				flags(t_format *form, char **str);
int					size(t_format *form, char **str);
void	precision(t_format *form, char **str, va_list *ap);
void	width(t_format *form, char **str, va_list *ap);
int 				conversion(t_format *form, char **str);
size_t	f_c(t_format *form, va_list *ap, char **buf);
size_t	f_s(t_format *form, va_list *ap, char **str);
int					ft_printf(char *str, ...);
void	get_strwidth(t_format *form, void **str, int count);
void	cast_signed(long long int *n, va_list *ap, t_format *f);
void	cast_unsigned(unsigned long long int *n, va_list *ap, t_format *f);
size_t	number_format(char **nbr, t_format *f);
size_t	f_pdiouxX(t_format *f, va_list *ap, char **str);
size_t	get_format_number1(t_format *f, void *n, char **str, int sig);
int 	count_digits(size_t digit);
char	*pow_bigint_toa(size_t n, size_t pow);
/*
 * 		Convert massive of integers to massive of characters.
 * 		In result we have number in string.
 */
char	*conv_to_strnum(int *mas, int len);
/*
 * 	bigintsum has two mods:
 * 	1 - ignored '0' befor number (a usual work);
 * 	0 - calculate numbers with '0' befor number (I wrote it for numbers which
 * 		has floating point (its decimal part)).
 */
char 	*bigintsum_toa(char *num1, char *num2, int mode);
/*
 * 	1 - add zeros start
 * 	0 - add zeros end
 */
void	add_0_for_numstr(char **num, int len_finish, int mode);
int		get_float_params(t_myfloat *mf, long double *n);
void	round_numstr(t_myfloat *mf, t_format *f);
char	*e_format(t_myfloat *mf, t_format *f);
char 	*f_format(t_myfloat *mf, t_format *f);
size_t	get_format_number2(t_format *f, long double *n, char **str);
size_t	f_feEgG(t_format *f, va_list *ap, char **str);
void	min_plus_space(char **nbr, t_format *f);
char 	*g_format(t_myfloat *mf, t_format *f);
void	set_color(t_pf *pf, char *color, size_t i, char **str);
size_t	text_color(t_pf *pf, char **str);
size_t	bg_color(t_pf *pf, char **str);
size_t	addition_options(t_pf *pf, char **str);
int		ft_printf2(char *str, ...);

#endif
