//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

void	get_strwidth(t_format *form, void **str, int count)
{
	*str = malloc(count);
	if (form->zero && !form->minus)
		ft_memset(*str, '0', count);
	else
		ft_memset(*str, ' ', count);
}