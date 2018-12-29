//
// Created by Vladyslav USLYSTYI on 26.12.2018.
//

#include "ft_printf.h"

size_t	check_minus(t_format *f, char **str, char *buf, size_t lenb)
{
    size_t  lens;
    char    *tmp;

    tmp = buf;
    lens = ft_strlen(*str);
    if ((f->precision && f->p_val >= lenb) || (!f->precision &&
        f->w_val > lenb && f->zero))
    {
        if (f->precision && f->p_val >= lenb)
            buf = ft_memalloc_chr(f->p_val + (tmp[0] == '-' ? 2 : 1), '0');
        else
            buf = ft_memalloc_chr(f->w_val + 1, '0');
        (tmp[0] == '-' && (tmp[0] = '0'));
        ft_memmove(buf + (ft_strlen(buf) - lenb), tmp, lenb);
        (tmp[0] == '0' && (buf[0] = '-'));
        free(tmp);
        lenb = ft_strlen(buf);
    }
    if (f->zero && lenb < lens && !f->precision)
        ft_memset(*str, '0', lens - lenb);
    ft_memmove(*str + (f->minus ? 0 : lens - lenb), buf, lenb);
    free(buf);
    return (lens);
}

size_t	get_good_width(t_format *f, long long int n, char **str)
{
    char    *buf;
    size_t  l;

    buf = ft_ltoa_base(n, 10);
    l = ft_strlen(buf);
    if (f->precision || f->w_val)
    {
        if (f->precision && f->w_val)
            if (f->w_val > f->p_val && f->w_val > l)
                *str = ft_memalloc_chr(f->w_val + 1, ' ');
            else if (f->p_val > f->w_val && f->p_val > l)
                *str = ft_memalloc_chr(f->p_val + (n < 0 ? 2 : 1), ' ');
            else
                *str = ft_memalloc_chr(l + 1, ' ');
        else if (f->precision)
            *str = ft_memalloc_chr((f->p_val > l ? f->p_val : l) +
                    (n < 0 && f->p_val >= l ? 2 : 1), ' ');
        else
            *str = ft_memalloc_chr((f->w_val > l ? f->w_val : l) + 1, ' ');
    }
    else
        *str = ft_memalloc_chr(l + 1, ' ');
    return (check_minus(f, str, buf, l));
}

size_t	f_d(t_format *f, va_list *ap, char **str)
{
	long long int	n;

	cast_d(&n, ap, f);
	if (f->minus && f->zero)
	    f->zero = 0;
	return (get_good_width(f, n, str));
}