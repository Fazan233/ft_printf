/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:58:41 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 16:59:10 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_conversation(t_format *f, int const *i)
{
	int count;

	count = -1;
	while (++count < 17)
		*i == count ? f->type = count : 0;
//	*i == 0 ? f->type = C : 0;
//	*i == 1 ? f->type = S : 0;
//	*i == 2 ? f->type = P : 0;
//	*i == 3 ? f->type = D : 0;
//	*i == 4 ? f->type = I : 0;
//	*i == 5 ? f->type = O : 0;
//	*i == 6 ? f->type = U : 0;
//	*i == 7 ? f->type = X : 0;
//	*i == 8 ? f->type = UPP_X : 0;
//	*i == 9 ? f->type = F : 0;
//	*i == 10 ? f->type = E : 0;
//	*i == 11 ? f->type = UPP_E : 0;
//	*i == 12 ? f->type = G : 0;
//	*i == 13 ? f->type = UPP_G : 0;
//	*i == 14 ? f->type = T : 0;
//	*i == 15 ? f->type = B : 0;
}

int			conversion(t_format *form, char **str)
{
	int	i;
	int check;

	check = 0;
	i = -1;
	while (CONVERSIONS[++i] != '\0')
	{
		if (CONVERSIONS[i] == **str)
		{
			set_conversation(form, &i);
			check = 1;
		}
	}
	*str = *str + 1;
	return (check);
}
