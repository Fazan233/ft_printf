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

	buf = ft_memalloc(1000);
	va_start(ap, str);
	if (find_flags(str, &form))
	{
		len = f_feEgG(&form, &ap, &buf);
		ft_putmem(buf, len);
	}
	va_end(ap);
	return (1);
}