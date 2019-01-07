//
// Created by angryjoe on 06.01.19.
//

#include "libft/libft.h"

void	add_0_befor_numstr(char **num, int len_finish)
{
	int		len_num;
	char	*tmp;

	len_num = ft_strlen(*num);
	if (len_num < len_finish)
	{
		tmp = (char*)ft_memalloc_chr(len_finish + 1, '0');
		ft_memmove(tmp + (len_finish - len_num), *num, len_num);
		free(*num);
		*num = tmp;
	}
}