//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"

size_t	f_pdiouxX(t_format *f, va_list *ap, char **str)
{
	void	*n;
	size_t 	len;

	n = malloc(16);
	if (f->minus && f->zero)
		f->zero = 0;
	if (f->type == P || (f->type >= O && f->type <= UPP_X))
		cast_unsigned((unsigned long long *) n, ap, f);
	else
		cast_signed((long long *) n, ap, f);
	len = get_format_number(f, n, str, 0);
	free(n);
	return (len);
}
