//
// Created by Vladyslav USLYSTYI on 26.12.2018.
//

#include "ft_printf.h"

void	cast_signed(long long int *n, va_list *ap, t_format *f)
{
	*n = va_arg(*ap, long long int);
	if (f->size)
	{
		if (f->s_val == 0)
			*n = (char) *n;
		else if (f->s_val == 1)
			*n = (short int) *n;
		else if (f->s_val == 3)
			*n = (long int) *n;
	}
	else
		*n = (int)*n;
}