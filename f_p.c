//
// Created by User on 20.12.2018.
//

#include "ft_printf.h"

int		check_minus(t_format *f, char **str, char *buf, int len_buf)
{
	char	*tmp;
	int 	len_str;
	int 	len_tmp;

	len_str = ft_strlen(*str);
	tmp = buf;
	buf = f->precision && f->p_val > len_buf ?
			ft_memalloc_chr(f->p_val + 3, '0') : ft_memalloc_chr(len_buf + 3, '0');
	buf[1] = 'x';
	len_tmp = ft_strlen(buf);
	ft_memmove(buf + (len_tmp - len_buf), tmp, len_buf);
	if (f->minus)
		ft_memmove(*str, buf, len_tmp);
	else
		ft_memmove(*str + (len_str - len_tmp), buf, len_tmp);
	free(buf);
	return (len_str);
}

int		get_good_width(t_format *f, char **str, size_t adr)
{
	char	*buf;
	int 	len;

	buf = ft_longtoa_base(adr, 16);
	len = ft_strlen(buf);
	if (f->precision || f->w_val)
	{
		if (f->precision && f->w_val)
			if (f->w_val >= f->p_val + 2 && f->w_val >= len + 2)
				*str = ft_memalloc_chr(f->w_val + 1, ' ');
			else if (f->w_val < f->p_val && f->p_val > len + 2)
				*str = ft_memalloc_chr(f->p_val + 3, ' ');
			else
				*str = ft_memalloc_chr(len + 3, ' ');
		else if (f->precision)
			*str = ft_memalloc_chr((f->p_val >= len ? f->p_val : len) +
					3, ' ');
		else
			*str = ft_memalloc_chr((f->w_val >= len + 2 ? f->w_val + 1 : len + 3),
					' ');
	}
	else
		*str = ft_memalloc_chr(len + 3, ' ');
	return (check_minus(f, str, buf, len));
}

size_t	*f_p(t_format *form, va_list *ap, char **str)
{
	void	*addres;

	addres = va_arg(*ap, void*);
	if (form->zero && form->w_val && !form->precision && !form->minus)
	{
		form->precision = 1;
		form->p_val = form->w_val - 2;
	}
	return ((size_t)get_good_width(form, str, addres));
}