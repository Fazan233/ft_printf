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
#include <printf.h>

#define FORM "%05%\n"

int main(void)
{

//	printf("%010+%");
//	int fd;
//	char *p = "string";
//
//	fd = open("test.txt", O_RDWR);
////	ft_putstr_fd("Hello", fd);
//	int i = 0;
	printf(FORM);
	ft_printf(FORM);
	return (0);
}