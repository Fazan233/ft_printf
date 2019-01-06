//
// Created by angryjoe on 05.01.19.
//

#include "ft_printf.h"

char	*pow_bigint_toa(size_t n, size_t pow)
{
	int		*mas;
	int 	i;
	int 	j;
	size_t 	len;

	len = pow * count_digits(n) + 10;
	mas = (int*)ft_memalloc(sizeof(int) * len);
	mas[0] = 1;
	i = -1;
	while (++i < pow)
	{
		j = 0;
		while (j < len)
			mas[j++] *= n;
		j = -1;
		while (++j < len - 1)
			if (mas[j] >= 10)
			{
				mas[j + 1] += mas[j] / 10;
				mas[j] %= 10;
			}
	}
	return (conv_to_strnum(mas, len));
}