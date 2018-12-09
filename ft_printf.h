/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:35:37 by vuslysty          #+#    #+#             */
/*   Updated: 2018/12/09 19:36:24 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct		s_flags
{
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	sharp:1;
	unsigned int	zero:1;
}					t_flags;

typedef struct		s_width
{
	unsigned int	width:1;
	int				val;
}					t_width;

typedef struct		s_precision
{
	unsigned int	precision:1;
	int				val;
}					t_precision;

typedef struct		s_conv_flags
{
	unsigned int	flag:1;
	char			buf[3];
}					t_conv_flags;

typedef struct		s_format
{
	t_flags			flags;
	t_width			width;
	t_precision		precision;
	t_conv_flags	conv_flags;
	char			type;
}					t_format;

#endif
