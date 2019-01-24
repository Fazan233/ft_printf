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
#define FORM "%0100.s\n", "Hello"

int main(void)
{
	double ld = -0.2;
	int i;
	i = 0;

	ft_printf("%+Tb", "HHHH");
//	printf(FORM);
//	ft_printf(FORM);

//	double a = 45.3;
//
//	printf(FORM);
//	ft_printf(FORM);
//
//	long int ld = 65536;
//	long double ldb = 1.0 / 0.0;
//	void *v = &ldb;
//	int i;
//	i = 16;
////	ft_putchar('\n');
//	while (--i >= 0)
//		ft_printf("%i", *((short int*)v + 4) >> i & 0b1);
//	ft_putchar('\n');
//	i = 64;
//	while (--i >= 0)
//		ft_printf("%hhi", *(t_ll *) v >> i & 0b1);
//	ft_printf("\n");
//
//	ft_printf("%L", ldb);
//	v = &ld;
//	i = 16;
//	ft_putchar('\n');
//	while (--i >= 0)
//		ft_printf("%i", *((short int*)v + 4) >> i & 0b1);


//	ld = 563870912;
//	int i = 4095;
//	ft_printf("%lb", 0.25);

//	printf("%Lu\n", 9999999999l);
//ft_printf("%Lu\n", 9999999999l);

//	ft_putnbr(ft_unistrlen("異体"));

	return (0);
}