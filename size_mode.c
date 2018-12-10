//
// Created by Vladyslav USLYSTYI on 10.12.2018.
//

#include "ft_printf.h"

char g_modeflags[MODE_FLAGS][3] = {"hh", "h", "ll", "l", "L"};

int		size(t_format *form, char **str)
{
	int 		i;

	i = -1;
	while (++i < MODE_FLAGS)
	{
		if (!ft_strncmp(*str, g_modeflags[i], ft_strlen(g_modeflags[i])))
		{
			*str = *str + ft_strlen(g_modeflags[i]);
			ft_strcpy(form->s_val, g_modeflags[i]);
			return (1);
		}
	}
	*str = *str + ft_strlen(g_modeflags[i]);
	return (0);
}