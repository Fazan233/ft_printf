//
// Created by angryjoe on 31.12.18.
//

#include "ft_printf.h"

size_t	number_format(char **nbr, t_format *f)
{
	int 	sign;
	size_t 	len;
	char	*tmp;

	sign = (*nbr)[0] == '-' ? 1 : 0;
	tmp = ft_strdup(*nbr + sign);
	free(nbr);
	if (f->precision && f->p_val > (len = ft_strlen(tmp)))
	{
		*nbr = ft_memalloc_chr(f->p_val, '0');
		ft_memmove(nbr + (f->p_val - len), tmp, len);
	}
	else
		*nbr = ft_strdup(tmp);
	free(tmp);
	if (sign || f->plus || f->space)
	{
		tmp = *nbr;
		if (sign)
			*nbr = ft_strjoin("-", *nbr);
		else
			*nbr = ft_strjoin((f->plus ? "+" : " "), *nbr);
		free(tmp);
	}
	return (ft_strlen(*nbr));
}