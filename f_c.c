//
// Created by Vladyslav USLYSTYI on 14.12.2018.
//

#include "ft_printf.h"

char	*f_c(t_format *form, va_list *ap)
{
	char	*str;
	int 	c;

	c = va_arg(*ap, int);
	if (form->w_val > 1)
	{
		get_strwidth(form, &str, form->w_val);
		if (form->minus)
		{
			if (c == 0)

			else
				str[0] = c;
		}
		else
			str[form->w_val - 1] = c;
	}
	else
	{
		str = ft_strdup("\u0000");
	}
	return (str);
}