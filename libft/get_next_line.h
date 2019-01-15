//
// Created by angryjoe on 15.01.19.
//

#ifndef PRINTF_GET_NEXT_LINE_H
# define PRINTF_GET_NEXT_LINE_H
# define BUF 32
# include <unistd.h>

int get_next_line(const int fd, char **line);

typedef struct		s_fdlst
{
	void			*data;
	int 			fd;
	struct s_fdlst	*next;
}					t_fdlst;

#endif //PRINTF_GET_NEXT_LINE_H
