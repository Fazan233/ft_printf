//
// Created by User on 25.12.2018.
//

#include "libft.h"

void		*ft_memalloc_chr(size_t size, char c)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	if (size > 1)
		ft_memset(mem, c, size - 1);
	((t_byte*)mem)[size - 1] = '\0';
	return (mem);
}