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
#define FORM "%#LG\n", 0.88888888888000007l

int main(void)
{
//	int fd;
//	char *line;
//
//	fd = open("test", O_RDONLY);
//	while (get_next_line(fd, &line))
//	{
//		ft_printf("%s\n", line);
//		free(line);
//	}

//	ft_putchar(34574);
//	ft_printf(FORM);
//	ft_printf("{RED}Привіт, пане Олексій");
	printf(FORM);
	ft_printf(FORM);
//	char *sum;
//	sum = ft_strdup("1");
//
//	int i = 10;
//	while (--i >= 0)
//	{
//		sum = bigintsum_toa(sum, pow_bigint_toa(2, 16500 - i), 1);
//	}
////	sum = bigintsum_toa(pow_bigint_toa(2, 15000), pow_bigint_toa(2, 16000), 1);
//	ft_printf2("%.200f", 3.24);
	return (0);
//	    printf(format, str, str);
}