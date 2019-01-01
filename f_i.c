//
// Created by angryjoe on 01.01.19.
//

#include "ft_printf.h"

size_t	f_i(t_format *f, va_list *ap, char **str)
{
	return (f_d(f, ap, str));
}