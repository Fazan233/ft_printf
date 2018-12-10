//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

void	flags(t_format *form, char **str)
{
	if (**str == '+')
		form->plus = 1;
	else if (**str == '-')
		form->minus = 1;
	else if (**str == ' ' )
		form->space = 1;
	else if (**str == '#')
		form->sharp = 1;
	else if (**str == '0')
		form->zero = 1;
	*str = *str + 1;
}