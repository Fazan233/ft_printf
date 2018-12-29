//
// Created by User on 20.12.2018.
//

#include "ft_printf.h"

static int		check_minus(t_format *f, char **str, char *buf, int lenb)
{
	char	*tmp;
	int 	lens;
	int 	lent;

	lens = ft_strlen(*str);
	tmp = buf;
	if (f->precision && f->p_val > lenb)
		buf = ft_memalloc_chr(f->p_val + 3, '0');
	else
		buf = ft_memalloc_chr(lenb + 3, '0');
	buf[1] = 'x';
	lent = ft_strlen(buf);
	ft_memmove(buf + (lent - lenb), tmp, lenb);
	if (f->minus)
		ft_memmove(*str, buf, lent);
	else
		ft_memmove(*str + (lens - lent), buf, lent);
	free(buf);
	free(tmp);
	return (lens);
}

static int		get_good_width(t_format *f, char **str, size_t adr)
{
	char	*buf;
	int 	l;

	buf = ft_ultoa_base(adr, 16);
	l = ft_strlen(buf);
	if (f->precision || f->w_val)
	{
		if (f->precision && f->w_val)
			if (f->w_val >= f->p_val + 2 && f->w_val >= l + 2)
				*str = ft_memalloc_chr(f->w_val + 1, ' ');
			else if (f->w_val < f->p_val && f->p_val > l + 2)
				*str = ft_memalloc_chr(f->p_val + 3, ' ');
			else
				*str = ft_memalloc_chr(l + 3, ' ');
		else if (f->precision)
			*str = ft_memalloc_chr((f->p_val >= l ? f->p_val : l) +
					3, ' ');
		else
			*str = ft_memalloc_chr((f->w_val >= l + 2 ? f->w_val + 1 : l + 3),
					' ');
	}
	else
		*str = ft_memalloc_chr(l + 3, ' ');
	return (check_minus(f, str, buf, l));
}

size_t	f_p(t_format *form, va_list *ap, char **str)
{
	void	*addres;

	addres = va_arg(*ap, void*);
	if (form->zero && form->w_val && !form->precision && !form->minus)
	{
		form->precision = 1;
		form->p_val = form->w_val - 2;
	}
	return ((size_t)get_good_width(form, str, (size_t)addres));
}