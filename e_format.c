//
// Created by angryjoe on 08.01.19.
//

#include "ft_printf.h"

void	e_plus(t_myfloat *mf, t_format *f)
{
	if (mf->len_i > 1)
	{
		mf->decimal = ft_strjoin_free(mf->intnum + 1, mf->decimal, 1);
		mf->exp_count += mf->len_i - 1;
		mf->intnum[1] = '\0';
	}
	mf->len_d = ft_strlen(mf->decimal);
	mf->len_i = ft_strlen(mf->intnum);
	round_numstr(mf, f);
	mf->len_d = ft_strlen(mf->decimal);
	mf->len_i = ft_strlen(mf->intnum);
	if (mf->len_i > 1)
		e_plus(mf, f);
}

void	e_minus(t_myfloat *mf, t_format *f)
{
	char *tmp;

	while (mf->decimal[mf->exp_count++] == '0');
	if (mf->len_d == 1 && mf->decimal[0] == '0')
		mf->exp_count = 0;

	else
	{
		tmp = mf->decimal;
		mf->intnum[0] = mf->decimal[mf->exp_count - 1];
		mf->decimal = ft_strdup(mf->decimal + mf->exp_count);
		free(tmp);
		mf->exp_sign = 1;
	}
}

char	*e_format(t_myfloat *mf, t_format *f)
{
	char 	*tmp;
	char 	*strnum;
	char 	*pow;

	mf->exp_sign = 0;
	mf->exp_count = 0;
	if (mf->len_i == 1 && mf->intnum[0] == '0')
		e_minus(mf, f);
	e_plus(mf, f);
	if (f->p_val != 0 || f->sharp)
		mf->intnum = ft_strjoin_free(mf->intnum, ".", 0);
	strnum = ft_strjoin(mf->intnum, mf->decimal);
	//I have to make this function work with e and E
	strnum = ft_strjoin_free(strnum, "e", 0);
	strnum = ft_strjoin_free(strnum, mf->exp_sign ? "-" : "+", 0);
	pow = ft_itoa(mf->exp_count);
	add_0_for_numstr(&pow, 2, 0);
	strnum = ft_strjoin_free(strnum, pow, 0);
	free(pow);
	return (strnum);
}