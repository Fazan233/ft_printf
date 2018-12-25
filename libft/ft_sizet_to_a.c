//
// Created by Vladyslav USLYSTYI on 25.12.2018.
//

#include "libft.h"

static char write_digit_base(int n)
{
	if (n >= 0 && n <= 9)
		return ('0' + n);
	else
		return ('a' + (n - 10));
}

static void rec_longtoa_base(size_t n, int base, int *len, char **str)
{
	(*len)++;
	if (n < base)
		*str = (char*)ft_memalloc(sizeof(char) * (*len + 1));
	else
		rec_longtoa_base(n / base, base, len, str);
	**str = write_digit_base((int)(n % base));
	(*str)++;
}

char	*ft_longtoa_base(size_t n, int base)
{
	char	*str;
	int 	len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_longtoa_base(n, base, &len, &str);
	return (str - len);
}