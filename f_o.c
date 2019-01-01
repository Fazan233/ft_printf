//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"

size_t	f_o(t_format *f, va_list *ap, char **str)
{
	void	*n;
	size_t 	len;

	n = malloc(16);
	if (f->minus && f->zero)
		f->zero = 0;
	if (f->type == 2 || (f->type >= 5 && f->type <= 8))
	{
		cast_unsigned((unsigned long long *) n, ap, f);
		len = get_format_number(f, (unsigned long long*)n, str, 1);
	}
	else
	{
		cast_signed((long long *) n, ap, f);
		len = get_format_number(f, (long long*)n, str, 0);
	}
	free(n);
	return (len);
}
