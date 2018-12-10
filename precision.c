//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

void	precision(t_format *form, char **str)
{
	form->precision = 1;
	*str = *str + 1;
	form->p_val = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str = *str + 1;
}