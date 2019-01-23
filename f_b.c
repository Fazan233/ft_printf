#include "ft_printf.h"

static int			get_right_count_mem(t_format *f, char **buf)
{
	int	bytes;

	if (f->size)
	{
		if (f->s_val == 0)
			bytes = 1;
		else if (f->s_val == 1)
			bytes = 2;
		else if (f->s_val == 2 || f->s_val == 5)
			bytes = 8;
		else if (f->s_val == 3)
			bytes = 4;
		else
			bytes = 10;
	}
	else
		bytes = 8;
	*buf = (char*)ft_memalloc((bytes * 8) + 1);
	return (bytes * 8);
}

static void		for_long_double(void *b, char **str)
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

static void		read_binary(void *b, t_format *f, char **str, int bits)
{
	int	i;

	i = 0;
	if (f->size)
		while (--bits >= 0)
			if (f->s_val == 0)
				(*str)[i++] = (*(t_byte*)b >> bits & 0b1) + '0';
			else if (f->s_val == 1)
				(*str)[i++] = (*(short int*)b >> bits & 0b1) + '0';
			else if (f->s_val == 2 || f->s_val == 5)
				(*str)[i++] = (*(t_ll*)b >> bits & 0b1) + '0';
			else if (f->s_val == 3 || f->s_val == 6)
				(*str)[i++] = (*(int*)b >> bits & 0b1) + '0';
			else
			{
				for_long_double(b, str);
				break ;
			}
	else
		(*str)[i++] = (*(t_ll*)b >> bits & 0b1) + '0';
}

size_t		f_b(t_format *form, va_list *ap, char **buf)
{
	void	*b;
	int 	bits;
	long double ld;
	long int li;
	double d;
	float f;

	if (form->s_val == 4)
	{
		ld = va_arg(*ap, long double);
		b = &ld;
	}
	else if (form->s_val == 5)
	{
		d = va_arg(*ap, double);
		b = &d;
	}
	else
	{
		li = va_arg(*ap, long int);
		b = &li;
	}
	form->plus ? form->plus = 0 : 0;
	bits = get_right_count_mem(form, buf);
	read_binary(b, form, buf, bits);
	return (bits);
}