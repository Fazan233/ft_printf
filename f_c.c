//
// Created by Vladyslav USLYSTYI on 14.12.2018.
//

#include "ft_printf.h"

size_t	f_c(t_format *form, va_list *ap, void **buf)
{
	int 	c;

	c = va_arg(*ap, int);
	if (form->w_val > 1)
	{
		get_strwidth(form, buf, form->w_val);
		if (form->minus)
			((char*)*buf)[0] = (char)c;
		else
			((char*)*buf)[form->w_val - 1] = (char)c;
	}
	else
		*buf = ft_memdup(&c, 1);
	return (form->w_val > 1 ? form->w_val : 1);
}