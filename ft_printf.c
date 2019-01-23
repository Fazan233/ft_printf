/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:05:14 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 19:05:25 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	good_flags(t_pf *pf, char **str)
{
	pf->form.p_val < 0 ? pf->form.p_val = 0 : 0;
	if (pf->form.type == T)
		pf->len += f_t(&pf->form, &pf->ap, &pf->buf);
	else
	{
		if (pf->form.type == C)
			pf->len_buf = f_c(&pf->form, &pf->ap, &pf->buf);
		else if (pf->form.type == S)
			pf->len_buf = f_s(&pf->form, &pf->ap, &pf->buf);
		else if (pf->form.type >= P && pf->form.type <= UPP_X)
			pf->len_buf = f_pdioux(&pf->form, &pf->ap, &pf->buf);
		else if (pf->form.type >= F && pf->form.type <= UPP_G)
			pf->len_buf = f_feg(&pf->form, &pf->ap, &pf->buf);
		else
			pf->len_buf = f_b(&pf->form, &pf->ap, &pf->buf);
		ft_putmem(pf->buf, pf->len_buf);
		pf->len += pf->len_buf;
		free(pf->buf);
	}
	pf->tmp = *str;
	pf->i = 0;
}

static void	can_set_color(t_pf *pf, char **str)
{
	if (text_color(pf, str))
		;
	else if (bg_color(pf, str))
		;
	else
		addition_options(pf, str);
}

//static void	condition(t_pf *pf, char **str)
//{
//	if (**str == '%')
//	{
//		ft_putmem(*str, 1);
//		*str = *str + 1;
//		pf->tmp = *str;
//		pf->i = 0;
//		pf->len++;
//	}
//	else if (**str != 0 && find_flags(str, &pf->form, &pf->ap))
//		good_flags(pf, str);
//	else if (**str != '\0' || pf->len > 0)
//	{
//		*str = pf->tmp + pf->i + 1;
//		pf->tmp += pf->i;
//		pf->i = 1;
//	}
//	else
//	{
//		pf->i = 0;
//		pf->len = -1;
//	}
//}

static void	condition(t_pf *pf, char **str)
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
	else
	{
		if (pf->form.w_val > 1)
		{
			pf->tmp = ft_memalloc_chr(pf->form.w_val, pf->form.zero ? '0' : ' ');
			ft_putmem(pf->tmp, pf->form.w_val - 1);
			free(pf->tmp);
		}
		pf->tmp = *str;
		pf->i = 0;
	}
}

static void	move_str(t_pf *pf, char **str)
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

int			ft_printf(char *str, ...)
{
	t_pf		pf;

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
