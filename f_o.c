//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"

size_t	f_o(t_format *f, va_list *ap, char **str)
{
	unsigned long long int	n;

	cast_unsigned(&n, ap, f);
	if (f->minus && f->zero)
		f->zero = 0;
	return (get_format_number(f, n, str));
}
