//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

void	good_flags(t_pf *pf, char **str)
{
	if (pf->form.type == C)
		pf->len_buf = f_c(&pf->form, &pf->ap, &pf->buf);
	else if (pf->form.type == S)
		pf->len_buf = f_s(&pf->form, &pf->ap, &pf->buf);
	else if (pf->form.type >= P && pf->form.type <= UPP_X)
		pf->len_buf = f_pdiouxX(&pf->form, &pf->ap, &pf->buf);
	else
		pf->len_buf = f_feEgG(&pf->form, &pf->ap, &pf->buf);
	ft_putmem(pf->buf, pf->len_buf);
	pf->len += pf->len_buf;
	free(pf->buf);
	pf->tmp = *str;
	pf->i = 0;
}

void	can_set_color(t_pf *pf, char **str)
{
	if (text_color(pf, str))
		;
	else if (bg_color(pf, str))
		;
	else
		addition_options(pf, str);
}

void	condition(t_pf *pf, char **str)
{
	if (**str == '%')
	{
		ft_putmem(*str, 1);
		*str = *str + 1;
		pf->tmp = *str;
		pf->i = 0;
		pf->len++;
	}
	else if (**str != 0 && find_flags(str, &pf->form, &pf->ap))
		good_flags(pf, str);
	else if (**str != '\0' || pf->len > 0)
	{
		*str = pf->tmp + pf->i + 1;
		pf->tmp += pf->i;
		pf->i = 1;
	}
	else
	{
		pf->i = 0;
		pf->len = -1;
	}
}

void	move_str(t_pf *pf, char **str)
{
	while (**str != 0)
	{
		if (**str == '{')
			can_set_color(pf, str);
		if (*((*str)++) != '%')
		{
			pf->i++;
			continue;
		}
		ft_putmem(pf->tmp, pf->i);
		pf->len += pf->i;
		condition(pf, str);
	}
}

int		ft_printf2(char *str, ...)
{
	t_pf		pf;
	char 		*temp;

	va_start(pf.ap, str);
	pf.i = 0;
	pf.len = 0;
	pf.tmp = str;
	move_str(&pf, &str);
	ft_putmem(pf.tmp, pf.i);
	pf.len += pf.i;
	va_end(pf.ap);
	return (pf.len);
}