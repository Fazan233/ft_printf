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
#define FORM "%.30Tb", "Привіт, я написав програму прінтф, яка працює з бінарниками."

int main(void)
{
	int fd;
	char *p = "string";

	fd = open("README.txt", O_RDONLY);
//	printf(FORM);
	int i = 0;
//	while (i < 128)
		ft_printf(FORM);
	return (0);
}