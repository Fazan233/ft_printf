//
// Created by Vladyslav USLYSTYI on 14.12.2018.
//

#include "ft_printf.h"

char	*f_c(t_format *form, va_list *ap)
{
	char	*str;

	if (form->w_val > 1)
	{
		get_strwidth(form, &str, form->w_val);
		if (form->minus)
			str[0] = (char)va_arg(*ap, int);
		else
			str[form->w_val - 1] = (char)va_arg(*ap, int);
	}
	else
	{
		str = (char*)ft_memalloc(2);
		str[0] = (char)va_arg(*ap, int);
	}
	return (str);
}