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

static void rec_utoa_base(unsigned long long n, int base, char **str, int *len)
{
	(*len)++;
	if (n < base)
		*str = (char *) ft_memalloc(sizeof(char) * (*len + 1));
	else
		rec_utoa_base(n / base, base, str, len);
	**str = write_digit_base((int)(n % base));
	(*str)++;
}

static void rec_stoa_base(long long n, int base, char **str, int *len)
{
	(*len)++;
	if (n > 0 ? n < base : n > -base)
	{
		*str = (char *) ft_memalloc(((n > 0 ? *len : ++(*len)) + 1));
		if (n < 0)
			*((*str)++) = '-';
	}
	else
		rec_stoa_base(n / base, base, str, len);
	**str = write_digit_base((int)((n > 0 ? n : -n) % base));
	(*str)++;
}

static void rec_itoa_base(int n, int base, char **str, int *len)
{
	(*len)++;
	if (n > 0 ? n < base : n > -base)
	{
		*str = (char *) ft_memalloc(((n > 0 ? *len : ++(*len)) + 1));
		if (n < 0)
			*((*str)++) = '-';
	}
	else
		rec_stoa_base(n / base, base, str, len);
	**str = write_digit_base((int)((n > 0 ? n : -n) % base));
	(*str)++;
}

char	*ft_toa_base(unsigned long long n, int base, char c)
{
	char	*str;
	int 	len;

	len = 0;
	if ((c == 'u' && n == 0) ||
		(c == 's' && (long long)n == 0))
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	if (c == 'u')
		rec_utoa_base(n, base, &str, &len);
	else if (c == 's')
		rec_stoa_base((long long)n, base, &str, &len);
	return (str - len);
}