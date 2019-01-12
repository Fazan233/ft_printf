//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

void	precision(t_format *form, char **str, va_list *ap)
{
	form->precision = 1;
	*str = *str + 1;
	if (**str == '*')
	{
		form->p_val = va_arg(*ap, int);
		*str = *str + 1;
	}
	else
	{
		form->p_val = ft_atoi(*str);
		while (ft_isdigit(**str))
			*str = *str + 1;
	}
}