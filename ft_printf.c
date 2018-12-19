//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_format 	form;

	va_start(ap, str);
	if (find_flags(str, &form))
	{
		ft_putstr(f_s(&form, &ap));
	}
	va_end(ap);
	return (1);
}