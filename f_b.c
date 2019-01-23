#include "ft_printf.h"

int			get_right_count_mem(t_format *f, char **buf)
{
	int	bytes;

	if (f->size)
	{
		if (f->s_val == 0)
			bytes = 1;
		else if (f->s_val == 1)
			bytes = 2;
		else if (f->s_val == 2)
			bytes = 8;
		else if (f->s_val == 3)
			bytes = 4;
		else
			bytes = 10;
	}
	else
		bytes = 16;
	*buf = (char*)ft_memalloc((bytes * 8) + 1);
	return (bytes * 8);
}

void		for_long_double(void *b, char **str)
{
	int	i;
	int shift;

	i = 0;
	shift = 16;
	while (--shift >= 0)
		(*str)[i++] = (*((short int*)b + 4) >> shift & 0b1) + '0';
	shift = 64;
	while (--shift >= 0)
		(*str)[i++] = (*(t_ll*)b >> shift & 0b1) + '0';
}

void		for_16bytes(void *b, char **str)
{
	int	i;
	int shift;
	int side;

	side = 1;
	i = 0;
	while (side >= 0)
	{
		shift = 64;
		while (--shift >= 0)
			(*str)[i++] = (*((t_ll *)b + side) >> shift & 0b1) + '0';
		side--;
	}
}

void		read_binary(void *b, t_format *f, char **str, int bits)
{
	int	i;

	i = 0;
	if (f->size)
		while (--bits >= 0)
			if (f->s_val == 0)
				(*str)[i++] = (*(t_byte*)b >> bits & 0b1) + '0';
			else if (f->s_val == 1)
				(*str)[i++] = (*(short int*)b >> bits & 0b1) + '0';
			else if (f->s_val == 2)
				(*str)[i++] = (*(t_ll*)b >> bits & 0b1) + '0';
			else if (f->s_val == 3)
				(*str)[i++] = (*(int*)b >> bits & 0b1) + '0';
			else
			{
				for_long_double(b, str);
				break ;
			}
	else
		for_16bytes(b, str);
}

size_t		f_b(t_format *form, va_list *ap, char **buf)
{
	void	*b;
	int 	bits;

	b = va_arg(*ap, void*);
	form->plus ? form->plus = 0 : 0;
	bits = get_right_count_mem(form, buf);
	read_binary(b, form, buf, bits);
}
