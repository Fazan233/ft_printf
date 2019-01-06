//
// Created by angryjoe on 06.01.19.
//

#include "libft/libft.h"

char	*conv_to_strnum(int *mas, int len)
{
	char	*str;
	int 	flag;
	int 	i;

	str = (char*)ft_memalloc(len + 1);
	flag = 1;
	i = -1;
	while (--len >= 0)
	{
		if (flag == 1)
		{
			if (mas[len] == 0)
				continue;
			else
				flag = 0;
		}
		str[++i] = '0' + mas[len];
	}
	free(mas);
	return (str);
}