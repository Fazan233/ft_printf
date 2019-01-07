//
// Created by angryjoe on 07.01.19.
//

#include "ft_printf.h"

char	*get_decimal(t_myfloat *f, int *i)
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
			add_0_befor_numstr(&pow_num, f->e);
			tmp_dec = decimal;
			decimal = bigintsum_toa(pow_num, decimal, 0);
			free(tmp_dec);
			free(pow_num);
		}
		f->e++;
		(*i)++;
	}
	return (decimal);
}

char 	*get_intnum(t_myfloat *f, int *i)
{
	char	*intnum;
	char 	*pow_num;
	char 	*tmp_in;

	intnum = ft_strdup("0");
	while ((*i) < MANTISS_LEN || f->e >= 0)
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

void	get_float_number(t_myfloat *f)
{
	int 	i;

	i = 0;
	f->intnum = (f->e < 0) ? ft_strdup("0") : get_intnum(f, &i);
	f->decimal = (f->e > MANTISS_LEN - 2) ? ft_strdup("0") : get_decimal(f, &i);
}