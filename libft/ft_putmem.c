//
// Created by Vladyslav USLYSTYI on 21.12.2018.
//

#include "../ft_printf.h"

void	ft_putmem(void *mem, size_t len)
{
	write(1, mem, len);
}