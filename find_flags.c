/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:28:40 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/09 21:50:01 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_to_zero(t_format *form)
{
	form->minus = 0;
	form->plus = 0;
	form->space = 0;
	form->sharp = 0;
	form->zero = 0;
	form->width = 0;
	form->precision = 0;
	form->size = 0;
}

int	find_flags(char *str, t_format *form)
{
	flags_to_zero(form);
	while (1)
	{
		if (ft_strchr(FLAGS, *str))
			flags(form, &str);
		else if (ft_isdigit(*str) && *str != '0')
			width(form, &str);
		else if (*str == '.')
			precision(form, &str);
		else if (size(form, &str))
			form->size = 1;
		else
		{
			if (ft_strchr(CONVERSIONS, *str))
			{
				form->type = *(str++);
				return (1);
			}
            return (0);
		}
	}
}
