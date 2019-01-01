//
// Created by angryjoe on 01.01.19.
//

void 	ft_strtoupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = 'A' + (*str - 'a');
		str++;
	}
}