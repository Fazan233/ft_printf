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

static void rec_toa_base(void *n, int base, char **str, char c)
{
	static int len = 1;
	if (n < base)
	{
		*str = (char *) ft_memalloc(sizeof(char) * (len + 1));
		len = 1;
	}
	else
	{
		len++;
		rec_toa_base(n / base, base, str);
	}
	**str = write_digit_base((int)(n % base));
	(*str)++;
}

char	*ft_toa_base(void *n, int base, char c)
{
	char	*str;

	if (*(int*)n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_toa_base(n, base, &str, c);

	return (str - len);
}