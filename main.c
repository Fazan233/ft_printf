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
	printf("width:     %*d\n", width, form->w_val);
	if (form->w_val)
		printf("width val is - %d\n", form->w_val);
	printf("precision: %*d\n", width, form->precision);
	if (form->precision)
		printf("precision val is - %d\n", form->p_val);
	printf("size:      %d\n", form->size);
	if (form->size)
		printf("mode val is - %d\n", (int)form->s_val);
	printf("type:      %d\n", form->type);
}

int main()
{
//	t_format form;
//	if (find_flags("22.4u", &form))
//		print_flags(&form);
	char *s = "Hello";
	char *str = "%Ld\n";
	long long i = -4232433949999999;
	printf(str, i);
	ft_printf(str + 1, i);
//	ft_putmem("Hello", 500);
	return (0);
}