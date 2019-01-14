////
//// Created by Vladyslav USLYSTYI on 19.12.2018.
////
//
//#include "ft_printf.h"
//
//void	good_flags(t_pf *pf, char **str)
//{
//	char 	*t;
//
//	if (pf->form.type == C)
//		pf->len_buf = f_c(&pf->form, &pf->ap, &pf->buf);
//	else if (pf->form.type == S)
//		pf->len_buf = f_s(&pf->form, &pf->ap, &pf->buf);
//	else if (pf->form.type >= P && pf->form.type <= UPP_X)
//		pf->len_buf = f_pdiouxX(&pf->form, &pf->ap, &pf->buf);
//	else
//		pf->len_buf = f_feEgG(&pf->form, &pf->ap, &pf->buf);
//	t = pf->form_str;
//	pf->form_str = ft_memjoin(pf->form_str, pf->len, pf->buf, pf->len_buf);
//	free(t);
//	pf->len += pf->len_buf;
//	free(pf->buf);
//	pf->tmp = *str;
//	pf->i = 0;
//}
//
//void	set_values(t_pf *pf, char **str)
//{
//	pf->i = 0;
//	pf->len = 0;
//	pf->tmp = *str;
//	pf->form_str = malloc(0);
//}
//
//void	can_set_color(t_pf *pf, char **str)
//{
//	if (text_color(pf, str))
//		;
//	else if (bg_color(pf, str))
//		;
//	else
//		addition_options(pf, str);
//}
//
//void	move_str(t_pf *pf, char **str)
//{
//	char	*t;
//
//	while (**str != 0)
//	{
//		if (**str == '{')
//			can_set_color(pf, str);
//		if (*((*str)++) != '%')
//		{
//			pf->i++;
//			continue;
//		}
//		t = pf->form_str;
//		pf->form_str = ft_memjoin(pf->form_str, pf->len, pf->tmp, pf->i);
//		free(t);
//		pf->len += pf->i;
//		if (find_flags(str, &pf->form, &pf->ap))
//			good_flags(pf, str);
//		else
//		{
//			*str = pf->tmp + pf->i + 1;
//			pf->tmp += pf->i;
//			pf->i = 1;
//		}
//	}
//}
//
//int		ft_printf(char *str, ...)
//{
////	va_list		ap;
////	t_format 	form;
////	void		*form_str;
////	void 		*buf;
////	size_t 		len_buf;
////	size_t		len;
////	int 		i;
////	t_byte 		*tmp;
//	t_pf		pf;
//	char 		*temp;
//
//	va_start(pf.ap, str);
//	set_values(&pf, &str);
//	move_str(&pf, &str);
//	temp = pf.form_str;
//	pf.form_str = ft_memjoin(pf.form_str, pf.len, pf.tmp, pf.i);
//	free(temp);
//	pf.len += pf.i;
//	ft_putmem(pf.form_str, pf.len);
//	free(pf.form_str);
//	va_end(pf.ap);
//	return (pf.len);
//}