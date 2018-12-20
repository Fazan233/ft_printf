//
// Created by User on 20.12.2018.
//

#include "ft_printf.h"

char 	*ret_nbr(size_t adr)
{
	char 	*nbr_str;
	char 	*buf;
	int		len;

	buf = ft_itoa_base(adr, 16);
	len = ft_strlen(buf);
	nbr_str = (char*)malloc(9);
	ft_memset(nbr_str, '0', 8);
	ft_memmove(nbr_str + (8 - len), buf, len);
	free(buf);
	return (nbr_str);
}

void	check_minus(t_format *form, char *str, size_t adr, int size)
{
	char	*buf;

	buf = ret_nbr(adr);
	if (form->minus)
	{
		if (form->sharp)
			ft_memmove(str, "0X", 2);
		ft_memmove(str + (form->minus ? 2 : 0), buf, 8);
	}
	else
	{
		if (form->sharp)
			ft_memmove(str + (size - 10), "0X", 2);
		ft_memmove(str + (size - 8), buf, 8);
	}
}

void	get_good_width(t_format *form, char **str, size_t adr)
{
	int 	tmp;

	if (form->w_val || form->sharp)
		if (form->sharp && form->w_val)
			*str = ft_memalloc(tmp = form->w_val > 10 ? form->w_val + 1 : 11);
		else if (form->w_val)
			*str = ft_memalloc(tmp = form->w_val > 8 ? form->w_val + 1 : 9);
		else
			*str = ft_memalloc(tmp = 11);
	else
		*str = ft_memalloc(tmp = 9);
	ft_memset(*str, ' ', tmp - 1);
	check_minus(form, *str, adr, tmp - 1);
}

char 	*f_p(t_format *form, va_list *ap)
{
	char 	*str;
	void	*addres;

	addres = va_arg(*ap, void*);
	get_good_width(form, &str, addres);
	return (str);
}