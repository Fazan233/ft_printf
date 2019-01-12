//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

void	width(t_format *form, char **str, va_list *ap)
{
	if (**str == '*')
	{
		form->w_val = va_arg(*ap, int);
		*str = *str + 1;
	}
	else
	{
		form->w_val = ft_atoi(*str);
		while (ft_isdigit(**str))
			*str = *str + 1;
	}
}