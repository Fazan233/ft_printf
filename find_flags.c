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
#include "libft/libft.h"

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

void	flags(t_format *form, char **str)
{
	if (**str == '+')
		form->plus = 1;
	if (**str == '-')
		form->minus = 1;
	if (**str == ' ' )
		form->space = 1;
	if (**str == '#')
		form->sharp = 1;
	if (**str == '0')
		form->zero = 1;
	*str++;
}

void	width(t_format *form, char **str)
{
	form->width = 1;
	form->w_val = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str++;
}

void	precision(t_format *form, char **str)
{
	form->precision = 1;
	*str++;
	form->p_val = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str++;
}

void	find_flags(char *str)
{
	t_format	form;

	flags_to_zero(&form);
	while (true)
	{
		if (*str == '+' || *str == '-' || *str == ' ' ||
			*str == '#' || *str == '0')
			flags(&form, &str);
		else if (ft_isdigit(*str) && *str != '0')
			width(&form, &str);
		else if (*str == '.')
			precision(&form, &str);
		//	else if ()
	}
}
