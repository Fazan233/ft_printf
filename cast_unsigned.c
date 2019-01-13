//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"

void	cast_unsigned(unsigned long long int *n, va_list *ap, t_format *f)
{
	if (f->type == P)
	{
		f->sharp = 1;
		*n = (va_arg(*ap, void*));
	}
	else
		*n = va_arg(*ap, unsigned long long int);
	if (f->type != P)
		if (f->size)
		{
			if (f->s_val == 0)
				*n = (unsigned char) *n;
			else if (f->s_val == 1)
				*n = (unsigned short int) *n;
			else if (f->s_val == 3)
				*n = (unsigned long int) *n;
		}
		else
			*n = (unsigned int)*n;
}