//
// Created by Vladyslav USLYSTYI on 21.12.2018.
//

#include "ft_printf.h"

void	*ft_memdup(void *mem, size_t len)
{
	void	*tmp;

	tmp = malloc(len);
	ft_memmove(tmp, mem, len);
	return (tmp);
}