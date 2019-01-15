//
// Created by angryjoe on 08.01.19.
//

#include "ft_printf.h"

static void	some_condition(t_myfloat *mf, t_format *f)
{
	char 	*one;
	char 	*tmp;

	if (mf->decimal[f->p_val] >= '5')
	{
		mf->decimal[f->p_val] = '\0';
		tmp = mf->decimal;
		one = ft_strdup("1");
		add_0_for_numstr(&one, f->p_val, 1);
		mf->decimal = bigintsum_toa(one, mf->decimal, 0);
		free(one);
		add_0_for_numstr(&mf->decimal, f->p_val, 1);
		free(tmp);
		if (f->p_val != ft_strlen(mf->decimal))
		{
			tmp = mf->intnum;
			mf->intnum = bigintsum_toa(mf->intnum, "1", 1);
			free(tmp);
			tmp = mf->decimal;
			mf->decimal = ft_strdup(mf->decimal + 1);
			free(tmp);
		}
	}
	else
		mf->decimal[f->p_val] = '\0';
}

void		round_numstr(t_myfloat *mf, t_format *f)
{
	!f->precision ? f->p_val = 6 : 0;
	if (f->p_val > mf->len_d)
		add_0_for_numstr(&mf->decimal, f->p_val, 0);
	else if (f->p_val < mf->len_d)
		some_condition(mf, f);
}