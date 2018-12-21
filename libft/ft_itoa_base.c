/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:08:02 by vuslysty          #+#    #+#             */
/*   Updated: 2018/11/07 14:14:45 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	write_digit_base(int n)
{
	if (n >= 0 && n <= 9)
		return ('0' + n);
	else
		return ('A' + (n - 10));
}

static void	rec_itoa_base(unsigned int nbr, int base, int *len,
									char **str)
{
	(*len)++;
	if (nbr < (unsigned int)base)
		*str = (char*)ft_memalloc(sizeof(char) * (*len + 1));
	else
		rec_itoa_base(nbr / base, base, len, str);
	**str = write_digit_base((int)(nbr % base));
	(*str)++;
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		len;

	len = 0;
	if (base == 10)
		return (ft_itoa(nbr));
	if (nbr == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	rec_itoa_base((unsigned int)nbr, base, &len, &str);
	*str = '\0';
	return (str - len);
}
