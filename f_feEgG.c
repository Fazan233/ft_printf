//
// Created by angryjoe on 08.01.19.
//

#include "ft_printf.h"

void	cast_float(long double *n, va_list *ap, t_format *f)
{
	if (!f->size || (f->size && f->s_val != 4))
		*n = va_arg(*ap, double);
	else
		*n = va_arg(*ap, long double);
}

size_t	f_feEgG(t_format *f, va_list *ap, char **str)
{
	long double	n;
	size_t 		len;

	if (f->minus && f->zero)
		f->zero = 0;
	cast_float(&n, ap, f);
	len = get_format_number2(f, &n, str);
	return (len);
}