//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

char 			g_modeflags[MODE_FLAGS][3] = {"hh", "h", "ll", "l", "L"};

int		size(t_format *form, char **str)
{
	int 		i;

	i = -1;
	while (++i < MODE_FLAGS)
		if (!ft_strncmp(*str, g_modeflags[i], ft_strlen(g_modeflags[i])))
		{
			form->s_val = i;
			break ;
		}
	*str = *str + ft_strlen(g_modeflags[i]);
	return ((i == MODE_FLAGS) ? 0 : 1);
}