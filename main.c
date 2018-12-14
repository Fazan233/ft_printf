/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:02:02 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/10 19:02:07 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_format *form)
{
	int		width = 20;

	printf("minus:     %*d\n", width, form->minus);
	printf("plus:      %*d\n", width, form->plus);
	printf("space:     %*d\n", width, form->space);
	printf("sharp:     %*d\n", width, form->sharp);
	printf("zero:      %*d\n", width, form->zero);
	printf("width:     %*d\n", width, form->width);
	if (form->width)
		printf("width val is - %d\n", form->w_val);
	printf("precision: %*d\n", width, form->precision);
	if (form->precision)
		printf("precision val is - %d\n", form->p_val);
	printf("size:      %*d\n", width, form->size);
	if (form->size)
		printf("mode val is - %s\n", form->s_val);
	printf("type:      %*c\n", width, form->type);
}

int main()
{
	t_format form;
//	find_flags("23Ls", &form);
//	print_flags(&form);
	printf("%p", 'o');
	return (0);
}