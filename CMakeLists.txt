cmake_minimum_required(VERSION 3.12)
project(printf C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(printf ${LIBA} find_flags.c ft_printf.h main.c flags.c precision.c width.c size_mode.c f_c.c conversion.c ft_printf.c f_s.c count_digits.c libft/ft_memdup.c libft/ft_memalloc_chr.c libft/ft_ulongtoa_base.c cast_signed.c libft/write_digit_base.c libft/ft_longtoa_base.c number_format.c libft/ft_strtoupper.c f_pdioux.c cast_unsigned.c pow_bignum_toa.c bigintsum_toa.c libft/ft_strreverse.c "conv_to_strnum.c" add_0_for_numstr.c get_float_params.c round_number.c get_format_number1.c f_feg.c get_format_number2.c f_format.c g_format.c set_color.c e_format.c get_exp_count.c f_b.c b_options.c libft/ft_putmem_fd.c ft_fprintf.c)
link_libraries(libft/libft.a)
