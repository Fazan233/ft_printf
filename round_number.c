//
// Created by angryjoe on 08.01.19.
//

#include "ft_printf.h"

void	round_numstr(t_myfloat *mf, t_format *f)
{
	char 	*tmp;

	!f->precision ? f->p_val = 6 : 0;
	if (f->p_val > mf->len_d)
		add_0_for_numstr(&mf->decimal, f->p_val, 0);
	else if (f->p_val < mf->len_d)
		if (mf->decimal[f->p_val] >= '5')
		{
			mf->decimal[f->p_val] = '\0';
			tmp = mf->decimal;
			mf->decimal = bigintsum_toa("1", mf->decimal, 1);
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