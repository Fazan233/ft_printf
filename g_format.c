//
// Created by angryjoe on 12.01.19.
//

#include "ft_printf.h"

char	*have_precision(t_myfloat *mf, t_format *f, int const *zeros)
{
	if (f->p_val < mf->len_i || (mf->intnum[0] && *zeros > 3))
	{
		f->p_val--;
		f->type = f->type == G ? E : UPP_E;
		return (e_format(mf, f));
	}
	else
	{
		if (mf->intnum[0] == '0')
			if (mf->len_d == 1 && mf->decimal[0] == '0')
				f->p_val--;
			else
				f->p_val = *zeros + f->p_val;
		else
			f->p_val -= mf->len_i;
		return (f_format(mf, f));
	}
}

char	*dont_have_precision(t_myfloat *mf, t_format *f, int const *zeros)
{
	f->precision = 1;
	if (mf->len_i > 6 || (mf->intnum[0] && *zeros > 3))
	{
		f->p_val = 5;
		f->type = f->type == G ? E : UPP_E;
		return (e_format(mf, f));
	}
	else
	{
		if (mf->intnum[0] == '0')
			if (mf->len_d == 1 && mf->decimal[0] == '0')
				f->p_val = 5;
			else
				f->p_val = 6 + *zeros;
		else
			f->p_val = 6 - mf->len_i;
		return (f_format(mf, f));
	}
}

void	check_sharp(char **strnum)
{
	int		len;
	char 	*b;
	char 	*a;

	if ((b = ft_strchr(*strnum, 'e')) || (b = ft_strchr(*strnum, 'E')))
	{
		a = b;
		while (*(--a) == '0')
			*a = '\0';
		*strnum = ft_strjoin_free(*strnum, b, 0);
	}
	if (ft_strchr(*strnum, '.'))
	{
		len = ft_strlen(*strnum);
		while ((*strnum)[len - 1] == '0' && len > 0)
			(*strnum)[len-- - 1] = '\0';
		if ((*strnum)[len - 1] == '.')
			(*strnum)[len - 1] = '\0';
	}
}

char 	*g_format(t_myfloat *mf, t_format *f)
{
	char 	*strnum;
	int 	zeros;

	zeros = 0;
	while (mf->decimal[zeros] == '0')
		zeros++;
	if (f->precision)
		strnum = have_precision(mf, f, &zeros);
	else
		strnum = dont_have_precision(mf, f, &zeros);
	if (!f->sharp)
		check_sharp(&strnum);
	return (strnum);
}