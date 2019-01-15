//
// Created by Vladyslav USLYSTYI on 19.12.2018.
//

#include "ft_printf.h"

static void	set_conversation(t_format *f, int const *i)
{
	*i == 0 ? f->type = C : 0;
	*i == 1 ? f->type = S : 0;
	*i == 2 ? f->type = P : 0;
	*i == 3 ? f->type = D : 0;
	*i == 4 ? f->type = I : 0;
	*i == 5 ? f->type = O : 0;
	*i == 6 ? f->type = U : 0;
	*i == 7 ? f->type = X : 0;
	*i == 8 ? f->type = UPP_X : 0;
	*i == 9 ? f->type = F : 0;
	*i == 10 ? f->type = E : 0;
	*i == 11 ? f->type = UPP_E : 0;
	*i == 12 ? f->type = G : 0;
	*i == 13 ? f->type = UPP_G : 0;
	*i == 14 ? f->type = T : 0;
}

int 		conversion(t_format *form, char **str)
{
	int	i;

	i = -1;
	while (CONVERSIONS[++i] != '\0')
	{
		if (CONVERSIONS[i] == **str)
		{
			set_conversation(form, &i);
			*str = *str + 1;
			return (1);
		}
	}
	return (0);
}