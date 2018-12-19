//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

int 	conversion(t_format *form, char **str)
{
	int	i;

	i = -1;
	while (CONVERSIONS[++i] != '\0')
	{
		if (CONVERSIONS[i] == **str)
		{
			form->type = i;
			*str = *str + 1;
			return (1);
		}
	}
	return (0);
}