/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:35:37 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/09 21:45:13 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

char g_flags[3][] =
{
	"Hello",
	"angry"
};

typedef struct		s_format
{
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	sharp:1;
	unsigned int	zero:1;
	unsigned int	width:1;
	unsigned int	precision:1;
	unsigned int	size:1;
	int				w_val;
	int				p_val;
	char			s_val[3];
	char			type;
}					t_format;

#endif
