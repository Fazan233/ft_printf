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

int main()
{
//	t_format form;
//	if (find_flags("22.4u", &form))
//		print_flags(&form);
	char *s = "Hello";
	char *str = "%+010.0d\n";
	int i = 10;
    printf(str, 0);
    ft_printf(str + 1, 0);
	return (0);
}