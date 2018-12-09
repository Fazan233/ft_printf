/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:28:40 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/09 20:03:45 by vuslysty         ###   ########.fr       */
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

void	flags(t_format *form, char c)
{
	if (c == '+')
		form->plus = 1;
	if (c == '-')
		form->minus = 1;
	if (c == ' ' )
		form->space = 1;
	if (c == '#')
		form->sharp = 1;
	if (c == '0')
		form->zero = 1;
}

void	find_flags(char *str)
{
	t_format	form;

	flags_to_zero(&form);
	while (true)
	{
		if (*str == '+' || *str == '-' || *str == ' ' ||
			*str == '#' || *str == '0')
			
	}
}
