//
// Created by angryjoe on 31.12.18.
//

#include "ft_printf.h"

void	set_nbr(char **nbr, t_format *f, size_t len, char *tmp)
{
	if (len == 1 && tmp[0] == '0' && f->precision && f->p_val == 0)
		*nbr = ft_strdup("");
	else if (f->precision && f->p_val > len)
	{
		*nbr = ft_memalloc_chr(f->p_val + 1, '0');
		ft_memmove(*nbr + (f->p_val - len), tmp, len);
	}
	else
		*nbr = ft_strdup(tmp);
	free(tmp);
}

void	min_plus_space(char **nbr, t_format *f, int sign)
{
	char	*tmp;

	if ((f->type >= 3 && f->type <= 4) && (sign || f->plus || f->space))
	{
		tmp = *nbr;
		if (sign)
			*nbr = ft_strjoin("-", *nbr);
		else
			*nbr = ft_strjoin((f->plus ? "+" : " "), *nbr);
		free(tmp);
	}
}

void	check_oxX(t_format *f, char **str)
{
	char	*tmp;

	tmp = *str;
	if (f->sharp && (f->type == 5 || f->type == 7 || f->type == 8))
	{
		if (f->type == 5)
			*str = ft_strjoin("0", *str);
		else
			*str = ft_strjoin("0x", *str);
		if (f->type == 8)
			ft_strtoupper(*str);
		free(tmp);
	}
}

size_t	number_format(char **nbr, t_format *f)
{
	int 	sign;
	size_t 	len;
	char	*tmp;

	sign = (*nbr)[0] == '-' ? 1 : 0;
	tmp = ft_strdup(*nbr + sign);
	free(*nbr);
	len = ft_strlen(tmp);
	set_nbr(nbr, f, len, tmp);
	check_oxX(f, nbr);
	min_plus_space(nbr, f, sign);
	return (ft_strlen(*nbr));
}