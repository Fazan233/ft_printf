cmake_minimum_required(VERSION 3.12)
project(printf C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(printf ${LIBA} find_flags.c ft_printf.h main.c flags.c precision.c width.c size_mode.c f_c.c conversion.c ft_printf.c f_s.c get_strwidth.c count_digits.c libft/ft_memjoin.c libft/ft_memdup.c libft/ft_putmem.c libft/ft_memalloc_chr.c libft/ft_ulongtoa_base.c cast_signed.c libft/write_digit_base.c libft/ft_longtoa_base.c number_format.c libft/ft_strtoupper.c f_pdiouxX.c cast_unsigned.c get_format_number.c pow_bignum_toa.c bigintsum_toa.c libft/ft_strreverse.c "conv_to_strnum (for bigint).c")
link_libraries(libft/libft.a)
