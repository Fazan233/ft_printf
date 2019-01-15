//
// Created by angryjoe on 15.01.19.
//

#include "get_next_line.h"
#include "libft.h"

//int 	check_endline()

t_fdlst	*get_right_list(const int fd, t_fdlst **list)
{
	t_fdlst *tmp;

	tmp = *list;
	if (tmp == NULL)
	{
		*list = (t_fdlst *) malloc(sizeof(t_fdlst));
		(*list)->fd = fd;
		(*list)->data = ft_memalloc(BUF + 1);
		(*list)->next = NULL;
		tmp = *list;
	}
	else
	{
		while (tmp != NULL && tmp->fd != fd)
			tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = (t_fdlst *) malloc(sizeof(t_fdlst));
			tmp->fd = fd;
			tmp->data = ft_memalloc(BUF + 1);
			tmp->next = *list;
			*list = tmp;
		}
	}
	return (tmp);
}

int 	get_next_line(const int fd, char **line)
{
	static t_fdlst	*list;
	t_fdlst			*tmp;


}