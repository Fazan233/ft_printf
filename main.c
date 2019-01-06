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

int main(void)
{
//	double n = 3.14;
//	unsigned char *p = &n;
//	printf("%.50f\n%.50f\n", n, (n - 3.0));
//	int i = 16;
//	while (--i >= 0)
//		printf("%-3.2x", *(p + i));
//	printf("\n%i", sizeof(long double));
//	ft_putstr(bigintsum_toa("0099", "099", 1));
	ft_putstr(pow_bigint_toa(2, 45));
	return (0);
}

//int main(void) /* C89 ANSI */
//{
//	int n[100] = { 1 };
//	/* число храним в достаточно длинном массиве
//	   первый элемент станет основанием,
//	   с которого число будет расти
//	   в сторону старших разрядов */
//
//	int base = 10;
//	/* полученное число будет в десятичной системе
//	   можно устанавливать степени десятки
//	   100, 1000, 10000 и так далее,
//	   это повысит скорость вычисления,
//	   результат будет выглядет одинаково;
//	   нужно учесть размер одного числа в массиве
//	   если int, то не более 10000 */
//
//	int i, j, flag;
//	/* i - внешние счётчики
//	   j - внутренние счётчики первого уровня
//	   flag - флажок, который при выводе числа
//			  помогает пропустить начальные нули в числе
//			  начальные нули - это разряды, до которых
//			  число не доросло */
//
//	for (i = 0; i < 345; i++) {
//
//		for (j = 0; j < 100; j++)
//			n[j] *= 2;
//		/* умножаем всё число на три,
//		   как будто в столбик на бумаге,
//		   для каждого разряда */
//
//		for (j = 0; j < 100-1; j++)
//			if (n[j] >= base) {
//				n[j+1] += n[j] / base;
//				n[j] %= base;
//			}
//		/* для всех разрядов, исключая самый старший,
//		   выполнить проверку на переполнение;
//
//		   если переполнение в каком-то из разрядов есть,
//		   то переполнившую часть перенести
//		   в соседний, более старший, разряд,
//		   а в самом разряде оставить остаток,
//		   который не переполняет разряд;
//
//		   при переносе переполнившей части
//		   в более старший соседний разряд,
//		   она прибавляется к тому, что уже там хранится */
//
//	}
//	/* умножает число на три сто раз,
//	   проводя проверки на переполнение его разрядов
//	   и переносы, в случаях переполнения */
//
//	flag = 1;
//	/* флаг пропуска начальных нулей
//	   устанавливается в положение "пропустить" */
//
//	for (i = 99; i >= 0; i--) {
//
//		if (flag == 1)
//			if (n[i] == 0)
//				continue;
//			else
//				flag = 0;
//		/* если флаг пропуска начальных нулей
//		   установлен в положение "пропустить",
//		   то проверить не началось ли число;
//
//		   если число началось,
//		   то есть встречен первый ненулевой разряд,
//		   то переключить флаг в положение "вывести";
//		   если число не началось,
//		   сразу перейти к следующему разряду,
//		   не выводя ничего */
//
//		printf("%d", n[i]);
//		/* выводит очередной разряд числа,
//		   начиная слева */
//	}
//	/* выводит получившееся число слева направо,
//	   поразрядно, начиная с первого ненулевого разряда */
//
//	putchar('\n');
//	/* после числа переводит строку */
//
//	exit(EXIT_SUCCESS);
//	/* возвращает статус успешного завершения
//	   в операционную среду */
//}

//int main()
//{
////	t_format form;
////	if (find_flags("22.4u", &form))
////		print_flags(&form);
////	char *s = "Hello";
////	char *str = "%s\n";
////	long double ld = 0.1234567890123456789 * 1e+308;
////	//12345678901234567168.00000000000000000000
////	printf("%Lf\n", ld);
////	unsigned int *voi = &ld;
////	s = ft_ultoa_base(*voi, 16);
////	ft_printf("s", s);
////	int i = 4;
////	char *tmp;
////	while (--i >= 0)
////	{
////		s = ft_ultoa_base(*(voi + i), 2);
////		size_t len = ft_strlen(s);
////		if (len < 8)
////		{
////			tmp = ft_memalloc_chr(9, '0');
////			ft_memmove(tmp, s, len);
////			free(s);
////			s = ft_strdup(tmp);
////			free(tmp);
////		}
////		ft_printf("s", s);
////		ft_putchar(' ');
////	}
////	printf("\n%.31f\n", ld);
//
////    unsigned int *a = &ld;
////    printf("%s", ft_ltoa_base(*a, 2));
//
//
//
////    ft_printf(str + 1, "Привітулі, дулі, дулі");
////	return (0);
//
//
//}