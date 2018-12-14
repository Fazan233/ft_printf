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
# define MODE_FLAGS 5
# define CONVERSIONS "cspdiouxXfeg"
# define FLAGS "+- #0"
# include <stdio.h>
# include "libft/libft.h"

enum	e_convers {c, s, p, d, i, o, u, x, X, f, e, g};
enum	e_size {hh, h, ll, l, L};

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
	char			s_val[3];
	enum e_convers			type;
	int				w_val;
	int				p_val;
}					t_format;

int					find_flags(char *str, t_format *form);
void				flags(t_format *form, char **str);
int					size(t_format *form, char **str);
void				precision(t_format *form, char **str);
void				width(t_format *form, char **str);

#endif
