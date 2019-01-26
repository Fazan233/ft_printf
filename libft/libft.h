/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuslysty <vuslysty@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:37:53 by vuslysty          #+#    #+#             */
/*   Updated: 2019/01/21 20:17:22 by vuslysty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;

char					*ft_strcpy(char *dst, const char *src);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcat(char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isdigit(int c);
char					*ft_strchr(const char *s, int c);
int						ft_atoi(const char *str);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memalloc(size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_itoa(int n);
int						ft_pow(int n, int pow);
void					*ft_memalloc_chr(size_t size, char c);
char					*ft_ultoa_base(unsigned long long n, int base);
char					*ft_ltoa_base(long long n, int base);
char					write_digit_base(int n);
void					ft_strtoupper(char *str);
void					*ft_memdup(void *mem, size_t len);
void					ft_strreverse(char *str);
char					*ft_strjoin_free(char *s1, char *s2, int mode);
void					ft_putmem_fd(void *mem, size_t len, int fd);

#endif
