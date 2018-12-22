//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

void	alloc_good_width(t_format *f, char **str, int len)
{
	if (f->precision || f->w_val)
	{
		if (f->precision && f->w_val)
			if (f->precision > f->p_val && f->p_val <= len)
				*str = (char*)ft_memalloc(f->p_val + 1);
			else
				*str = (char*)ft_memalloc(f->w_val + 1);
		else if (f->precision)
			*str = (char*)ft_memalloc(1 + f->p_val <= len ? f->p_val : len);
		else
			*str = (char*)ft_memalloc(f->w_val + 1);
	}
	else
		*str = (char*)ft_memalloc(len + 1);
	
}

void	oper_with_minus(t_format *form, char *str, char *buf, int len_buf)
{
	int 	len_str;
	int 	tmp;

	len_str = ft_strlen(str);
	tmp = (len_buf < form->p_val) ? len_buf : form->p_val;
	if (!form->w_val && !form->precision)
		ft_strcpy(str, buf);
	else if (form->minus)
	{
		ft_memset(str, ' ', len_str);
		if (form->precision)
			ft_memmove(str, buf, tmp);
		else
			ft_memmove(str, buf, len_buf);
	}
	else
		if (form->precision)
			ft_memmove(str + (len_str - tmp), buf, tmp);
		else
			ft_memmove(str + (len_str - len_buf), buf, len_buf);
}

size_t	f_s(t_format *form, va_list *ap, void **str)
{
	char 	*buf;
	int 	len;

	buf = ft_strdup(va_arg(*ap, char*));
	len = ft_strlen(buf);
	alloc_good_width(form, str, len);
	oper_with_minus(form, *str, buf, len);
	free(buf);
	return ();
}