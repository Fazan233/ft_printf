//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"
#include <stdlib.h>

static char	*get_good_func(void *n, t_format *f)
{
	char	*buf;
	int 	base;

	if (f->type == D || f->type == I || f->type == U)
		base = 10;
	else if (f->type == O)
		base = 8;
	else
		base = 16;
	if (f->type == D || f->type == I)
		buf = ft_ltoa_base(*(long long*)n, base);
	else
		buf = ft_ultoa_base(*(unsigned long long*)n, base);
	if (f->type != P && buf[0] == '0' && f->precision && f->p_val == 0)
		buf[0] = '\0';
	return (buf);
}

size_t		get_format_number1(t_format *f, void *n, char **str, int sig)
{
	char    *buf;
	size_t  lb;
	size_t  ls;

	buf = get_good_func(n, f);
	lb = number_format(&buf, f);
	if (f->w_val > lb)
		*str = ft_memalloc_chr((ls = f->w_val) + 1,
							   f->zero && !f->precision ? '0' : ' ');
	else
		*str = ft_memalloc_chr((ls = lb) + 1, ' ');
	if (f->minus)
		ft_memmove(*str, buf, lb);
	else
		if (f->w_val > lb && f->zero && !f->precision &&
			(buf[0] == '-' || buf[0] == '+' || buf[0] == ' '))
		{
			ft_memmove(*str + (ls - lb + 1), buf + 1, lb - 1);
			(*str)[0] = buf[0];
		}
		else
			ft_memmove(*str + (ls - lb), buf, lb);
	free(buf);
	return (ls);
}