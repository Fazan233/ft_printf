//
// Created by angryjoe on 06.01.19.
//

#include "libft.h"

void	ft_strreverse(char *str)
{
	int		len;
	int 	i;
	int 	j;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
}