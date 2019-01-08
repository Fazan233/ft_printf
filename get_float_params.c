//
// Created by angryjoe on 06.01.19.
//

#include "ft_printf.h"

static char	*get_decimal(t_myfloat *f, int *i)
{
	char 	*decimal;
	char 	*pow_num;
	char 	*tmp_dec;

	decimal = ft_strdup("0");
	f->e = ABS(f->e);
	while ((*i) < MANTISS_LEN)
	{
		if (f->m >> (MANTISS_LEN - 1 - *i) & 0b1)
		{
			pow_num = pow_bigint_toa(5, f->e);
			add_0_for_numstr(&pow_num, f->e, 1);
			tmp_dec = decimal;
			decimal = bigintsum_toa(pow_num, decimal, 0);
			add_0_for_numstr(&decimal, f->e, 1);
			free(tmp_dec);
			free(pow_num);
		}
		f->e++;
		(*i)++;
	}
	return (decimal);
}

static char	*get_intnum(t_myfloat *f, int *i)
{
	char	*intnum;
	char 	*pow_num;
	char 	*tmp_in;

	intnum = ft_strdup("0");
	while ((*i) < MANTISS_LEN && f->e >= 0)
	{
		if (f->m >> (MANTISS_LEN - 1 - *i) & 0b1)
		{
			pow_num = pow_bigint_toa(2, f->e);
			tmp_in = intnum;
			intnum = bigintsum_toa(pow_num, intnum, 1);
			free(tmp_in);
			free(pow_num);
		}
		f->e--;
		(*i)++;
	}
	return (intnum);
}

static void	get_float_number(t_myfloat *f)
{
	int 	i;

	i = 0;
	f->intnum = (f->e < 0) ? ft_strdup("0") : get_intnum(f, &i);
	f->decimal = (f->e > MANTISS_LEN - 2) ? ft_strdup("0") : get_decimal(f, &i);
}

void	get_float_params(t_myfloat *mf, long double *n)
{
	t_ull			*mantiss;
	unsigned short	*s_exp;
	char 			*tmp;

	mantiss = n;
	mf->m = *mantiss;
	s_exp = n;
	s_exp += 4;
	mf->s = *s_exp >> 15 & 0b1;
	mf->e = (*s_exp & (short)0x7fff) - 0x3fff;
	get_float_number(mf);
//	if (mf->s)
//	{
//		tmp = mf->intnum;
//		mf->intnum = ft_strjoin("-", mf->intnum);
//		free(tmp);
//	}
}