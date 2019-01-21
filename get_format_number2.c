/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_number2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:32:29 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:35:40 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SIGN (buf[0] == '-' || buf[0] == '+' || buf[0] == ' ')

static char	*get_good_flag(long double *n, t_format *f)
{
	char		*numstr;
	int			inf;
	t_myfloat	mf;

	inf = get_float_params(&mf, n);
	f->sign = mf.s;
	if (inf)
	{
		numstr = ft_strdup("inf");
		f->zero = 0;
	}
	else if (f->type == F)
		numstr = f_format(&mf, f);
	else if (f->type == E || f->type == UPP_E)
		numstr = e_format(&mf, f);
	else
		numstr = g_format(&mf, f);
	min_plus_space(&numstr, f);
	if (!inf)
	{
		free(mf.intnum);
		free(mf.decimal);
	}
	return (numstr);
}

size_t		get_format_number2(t_format *f, long double *n, char **str)
{
	char		*buf;
	size_t		lb;
	size_t		ls;

	buf = get_good_flag(n, f);
	lb = ft_strlen(buf);
	if (f->w_val > lb)
		*str = ft_memalloc_chr(f->w_val + 1, f->zero ? '0' : ' ');
	else
		*str = ft_memalloc_chr(lb + 1, ' ');
	ls = f->w_val > lb ? f->w_val : lb;
	if (f->minus)
		ft_memmove(*str, buf, lb);
	else
	{
		if (f->w_val > lb && f->zero && SIGN)
		{
			ft_memmove(*str + (ls - lb + 1), buf + 1, lb - 1);
			(*str)[0] = buf[0];
		}
		else
			ft_memmove(*str + (ls - lb), buf, lb);
	}
	free(buf);
	return (ls);
}
