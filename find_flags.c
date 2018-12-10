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
#include <stdio.h>

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

int		size(t_format *form, char **str)
{
	int 		i;

	i = -1;
	while (++i < MODE_FLAGS)
	{
		if (ft_strncmp(*str, g_modeflags[i], ft_strlen(g_modeflags[i])))
		{
			*str = *str + ft_strlen(g_modeflags[i]);
			ft_strcpy(form->s_val, g_modeflags[i]);
			return (1);
		}
	}
	return (0);
}

void	print_flags(t_format *form)
{
	int		width = 12;

	printf("minus: %*d\n", width, form->minus);
	printf("plus: %*d\n", width, form->plus);
	printf("space: %*d\n", width, form->space);
	printf("sharp: %*d\n", width, form->sharp);
	printf("zero: %*d\n", width, form->zero);
	printf("width: %*d\n", width, form->width);
	if (form->width)
		printf("width val is - %d\n", form->w_val);
	printf("precision: %*d\n", width, form->precision);
	if (form->precision)
		printf("precision val is - %d\n", form->p_val);
	printf("size: %*d\n", width, form->size);
	if (form->size)
		printf("mode val is - %s\n", form->s_val);
	printf("type: %*d\n", width, form->type);
}

void	find_flags(char *str)
{
	t_format	form;

	flags_to_zero(&form);
	while (1)
	{
		if (*str == '+' || *str == '-' || *str == ' ' ||
			*str == '#' || *str == '0')
			flags(&form, &str);
		else if (ft_isdigit(*str) && *str != '0')
			width(&form, &str);
		else if (*str == '.')
			precision(&form, &str);
		else if (size(&form, &str))
			form.size = 1;
		else if (ft_strchr(g_conversions, *str))
		{
			form.type = *str;
			print_flags(&form);
			break ;
		}
	}
}
