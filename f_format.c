//
// Created by angryjoe on 09.01.19.
//

#include "ft_printf.h"

char 	*f_format(t_myfloat *mf, t_format *f)
{
	char 	*strnum;

	round_numstr(mf, f, f->p_val);
	if (f->p_val != 0 || f->sharp)
		mf->intnum = ft_strjoin_free(mf->intnum, ".", 0);
	strnum = ft_strjoin(mf->intnum, mf->decimal);
	return (strnum);
}