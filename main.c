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
	char *str = "%-04.3d\n";
//	long long i = -4232433949999999;
//	printf(str, i);
//	ft_printf(str + 1, i);
//	ft_putmem("Hello", 500);
	long long i = 16;
//	ft_putstr(ft_toa_base((int)1844674407369705161, 16, 'u'));
    printf(str, 52);
//    ft_printf(str + 1, i);
	return (0);
}