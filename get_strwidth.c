//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

void	get_strwidth(t_format *form, char **str, int count)
{
	*str = (char*)ft_memalloc(count + 1);
	if (form->zero)
		ft_memset(*str, '0', count);
	else
		ft_memset(*str, ' ', count);
}