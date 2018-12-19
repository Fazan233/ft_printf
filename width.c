//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

void	width(t_format *form, char **str)
{
	form->w_val = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str = *str + 1;
}