//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list		ap;
	t_format 	form;
	char		*buf;
	size_t 		len;

	va_start(ap, str);
	if (find_flags(str, &form, &ap))
	{
		len = f_pdiouxX(&form, &ap, &buf);
		ft_putmem(buf, len);
		free(buf);
	}
	va_end(ap);
	return (1);
}