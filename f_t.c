//
// Created by angryjoe on 15.01.19.
//

#include "ft_printf.h"

size_t		f_t(t_format *f, va_list *ap, char **str)
{
	int	fd;
	int len_sum;
	int len_str;
	int count;

	count = 0;
	len_sum = 0;
	fd = va_arg(*ap, int);
	while (get_next_line(fd, str) > 0)
	{
		len_sum += (len_str = ft_strlen(*str));
		if (f->minus && len_str == 0)
		{
			free(*str);
			continue;
		}
		count++;
		ft_putmem(*str, len_str);
		free(*str);
		if (f->plus && ++len_sum)
			ft_putchar('\n');
		else if (f->space && ++len_sum)
			ft_putchar(' ');
		if (f->precision && f->p_val == count)
			break;
	}
	return (len_sum);
}