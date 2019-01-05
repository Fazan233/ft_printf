//
// Created by User on 20.12.2018.
//

#include "libft/libft.h"

int 	count_digits(size_t digit)
{
	static int	len = 0;

	if (digit / 10 == 0)
		return (++len);
	else{
		len++;
		return (count_digits(digit / 10));
	}
}