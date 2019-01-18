//
// Created by Vladyslav USLYSTYI on 2019-01-18.
//

#include "ft_printf.h"

void 	get_exp_count(t_myfloat *mf)
{
	int zeros;

	mf->exp_sign = 0;
	mf->exp_count = 0;
	zeros = 0;
	while (mf->decimal[zeros] != '\0')
		if (mf->decimal[zeros++] != '0')
		{
			zeros = 0;
			break ;
		}
	if (mf->intnum[0] == '0' && !(mf->decimal[0] == '0' && zeros != 0))
	{
		mf->exp_sign = 1;
		while (mf->decimal[mf->exp_count++] == '0')
			;
	}
	else if (mf->intnum[0] != '0' && mf->len_i != 1)
	{
		mf->exp_sign = 0;
		mf->exp_count = mf->len_i - 1;
	}
}