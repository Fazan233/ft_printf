/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:56:51 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:00:46 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_ltoa_base(long long n, int base, char **str, int *len)
{
	(*len)++;
	if (n > 0 ? n < base : n > -base)
	{
		*str = (char*)ft_memalloc(((size_t)(n > 0 ? *len : ++(*len)) + 1));
		if (n < 0)
			*((*str)++) = '-';
	}
	else
		rec_ltoa_base(n / base, base, str, len);
	**str = write_digit_base((int)((n > 0 ? n : -n) % base));
	(*str)++;
}

char		*ft_ltoa_base(long long n, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	rec_ltoa_base(n, base, &str, &len);
	return (str - len);
}
