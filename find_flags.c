/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:28:40 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 18:58:44 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_to_zero(t_format *form)
{
	form->minus = 0;
	form->plus = 0;
	form->space = 0;
	form->sharp = 0;
	form->zero = 0;
	form->w_val = 0;
	form->precision = 0;
	form->size = 0;
}

int			find_flags(char **str, t_format *form, va_list *ap)
{
	int check_conv;

	check_conv = 0;
	flags_to_zero(form);
	while (**str != 0 && check_conv == 0)
	{
		check_conv = 0;
		if (ft_strchr(FLAGS, **str))
			flags(form, str);
		else if (**str == '*' || (ft_isdigit(**str) && **str != '0'))
			width(form, str, ap);
		else if (**str == '.')
			precision(form, str, ap);
		else if (size(form, str))
			form->size = 1;
		else if (conversion(form, str))
			check_conv = 1;
	}
	return (check_conv);
}
