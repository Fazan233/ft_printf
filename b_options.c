//
// Created by Vladyslav USLYSTYI on 2019-01-24.
//

#include "ft_printf.h"

void		b_flag_plus(char **buf, int bits, int spaces)
{
	char 	*tmp_buf;
	int 	i;
	char 	*tmp;
	char 	*formated_binary;

	tmp_buf = *buf;
	tmp = (char*)ft_memalloc_chr((bits + spaces + 1), ' ');
	formated_binary = tmp;
	i = 0;
	while (*tmp_buf != 0)
	{
		if (++i % 9 == 0 && spaces--)
		{
			tmp++;
			i = 0;
			continue;
		}
		*tmp++ = *tmp_buf++;
	}
	free(*buf);
	*buf = formated_binary;
}

void		b_size_mode_T(char *buf, void *b, t_format *f)
{
	int		i;
	char 	*tmp;

	i = 0;
	while (*(char*)b != 0)
	{
		read_binary(b, f, buf + i, 8);
		i += 8;
		b = (char*)b + 1;
	}
}