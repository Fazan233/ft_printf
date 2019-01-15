//
// Created by Vladyslav USLYSTYI on 21.12.2018.
//

#include "../ft_printf.h"

void 	*ft_memjoin(void *mem1, size_t len1, void *mem2, size_t len2)
{
	void	*buf;

	buf = malloc(len1 + len2 + 1);
	ft_memmove(buf, mem1, len1);
	ft_memmove(buf + len1, mem2, len2);
	return (buf);
}