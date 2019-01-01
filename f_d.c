//
// Created by Vladyslav USLYSTYI on 26.12.2018.
//

#include "ft_printf.h"

static size_t	get_good_width(t_format *f, long long int n, char **str)
{
    char    *buf;
    size_t  lb;
    size_t  ls;

    buf = ft_ltoa_base(n, 10);
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

size_t	f_d(t_format *f, va_list *ap, char **str)
{
	long long int	n;

	cast_signed(&n, ap, f);
	if (f->minus && f->zero)
	    f->zero = 0;
	return (get_good_width(f, n, str));
}