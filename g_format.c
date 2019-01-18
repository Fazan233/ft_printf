//
// Created by angryjoe on 12.01.19.
//

#include "ft_printf.h"

//static char	*have_precision(t_myfloat *mf, t_format *f, int const *zeros)
//{
//	if (f->p_val < mf->len_i || (mf->intnum[0] && *zeros > 3))
//	{
//		f->p_val--;
//		f->type = f->type == G ? E : UPP_E;
//		return (e_format(mf, f));
//	}
//	else
//	{
//		if (mf->intnum[0] == '0')
//			if (mf->len_d == 1 && mf->decimal[0] == '0')
//				f->p_val--;
//			else
//				f->p_val = *zeros + f->p_val;
//		else
//			f->p_val -= mf->len_i;
//		return (f_format(mf, f));
//	}
//}
//
//static char	*dont_have_precision(t_myfloat *mf, t_format *f, int const *zeros)
//{
//	f->precision = 1;
//	if (mf->len_i > 6 || (mf->intnum[0] == '0' && *zeros > 3))
//	{
//		f->p_val = 5;
//		f->type = f->type == G ? E : UPP_E;
//		return (e_format(mf, f));
//	}
//	else
//	{
//		if (mf->intnum[0] == '0')
//			if (mf->len_d == 1 && mf->decimal[0] == '0')
//				f->p_val = 5;
//			else
//				f->p_val = 6 + *zeros;
//		else
//			f->p_val = 6 - mf->len_i;
//		return (f_format(mf, f));
//	}
//}
//
//static void	check_sharp(char **strnum)
//{
//	int		len;
//	char 	*b;
//	char 	*a;
//
//	if ((b = ft_strchr(*strnum, 'e')) || (b = ft_strchr(*strnum, 'E')))
//	{
//		a = b;
//		while (*(--a) == '0')
//			*a = '\0';
//		if (*a == '.')
//			*a = '\0';
//		*strnum = ft_strjoin_free(*strnum, b, 0);
//	}
//	else if (ft_strchr(*strnum, '.'))
//	{
//		len = ft_strlen(*strnum);
//		while ((*strnum)[len - 1] == '0' && len > 0)
//			(*strnum)[len-- - 1] = '\0';
//		if ((*strnum)[len - 1] == '.')
//			(*strnum)[len - 1] = '\0';
//	}
//}
//
//static int 		get_exp_count(t_myfloat *mf)
//{
//	int 	exp;
//
//	exp = 0;
//	while (mf->intnum[0] == '0' && mf->decimal[exp++] == '0')
//		;
//	if (mf->decimal[exp - 1] == '\0')
//		exp = -1;
//	return (exp);
//}
//
//char 		*g_format(t_myfloat *mf, t_format *f)
//{
//	char 	*strnum;
//
//	f->p_val = !f->precision ? 6 : f->p_val;
//	f->precision = 1;
//	f->p_val == 0 ? f->p_val = 1 : 0;
//	mf->exp_count = get_exp_count(mf);
//	if ((mf->intnum[0] == '0' && mf->exp_count > 4) || (mf->len_i > f->p_val))
//	{
//		f->p_val--;
//		strnum = e_format(mf, f);
//	}
//	else
//	{
//		if (mf->intnum[0] != '0')
//			f->p_val = f->p_val - mf->len_i;
//		else if (mf->intnum[0] && mf->exp_count == -1)
//			f->p_val--;
//		else
//			f->p_val = f->p_val + mf->exp_count - 1;
//		round_numstr(mf, f, f->p_val);
//		strnum = f_format(mf, f);
//	}
//	return (strnum);
//}