cmake_minimum_required(VERSION 3.12)
project(printf C)

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(libft LIBA)
add_executable(printf ${LIBA} find_flags.c ft_printf.h main.c flags.c precision.c width.c size_mode.c f_c.c conversion.c ft_printf.c f_s.c get_strwidth.c f_p.c count_digits.c libft/ft_itoa_base.c)
link_libraries(libft/libft.a)
