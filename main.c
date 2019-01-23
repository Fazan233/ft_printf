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

#include <fcntl.h>
#include "ft_printf.h"
#include <float.h>
#define FORM "%X\n", 34

int main(void)
{
//	double a = 45.3;
//
//	printf(FORM);
//	ft_printf(FORM);
//
	long double ld = 0.0624;
	void *v = &ld;
	int i = 64;
	while (--i >= 0)
		ft_printf("%lli", *(t_ll*)v >> i & 0b1);
	v = &ld;
	i = 16;
	ft_putchar('\n');
	while (--i >= 0)
		ft_printf("%i", *((short int*)v + 4) >> i & 0b1);


//	printf("%Lu\n", 9999999999l);
//ft_printf("%Lu\n", 9999999999l);

//	ft_putnbr(ft_unistrlen("異体"));

	return (0);
}