//
// Created by angryjoe on 14.01.19.
//

#include "ft_printf.h"

void	set_color(t_pf *pf, char *color, size_t i, char **str)
{
	int		color_len;
	char 	*tmp;

	color_len = ft_strlen(color);
	tmp = pf->form_str;
	pf->form_str = ft_memjoin(pf->form_str, pf->len, pf->tmp, pf->i);
	free(tmp);
	pf->len += pf->i;
	tmp = pf->form_str;
	pf->form_str = ft_memjoin(pf->form_str, pf->len, color, color_len);
	free(tmp);
	pf->len += color_len;
	*str = *str + (i - 1);
	pf->tmp = *str + 1;
	pf->i = -1;
}