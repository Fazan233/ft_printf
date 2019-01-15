//
// Created by angryjoe on 15.01.19.
//

#include "get_next_line.h"
#include "libft.h"

int 	check_endline(t_fdlst *list, char **line)
{
	int 	i;
	int 	len;
	char 	*tmp;

	i = -1;
	while (((char*)list->data)[++i] != '\0')
	{
		if (((char*)list->data)[i] == '\n')
		{
			tmp = *line;
			*line = ft_memjoin(*line, len = ft_strlen(*line), list->data, i);
			free(tmp);
			(*line)[len] = '\0';
			ft_strcpy(list->data, list->data + i);
			return (1);
		}
	}
	tmp = *line;
	*line = ft_memjoin(*line, ft_strlen(*line), list->data, i);
	free(tmp);
	return (0);
}

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
	int 			rd;

	tmp = get_right_list(fd, &list);
	if (check_endline(tmp, line))
		return (1);
	while ((rd = read(tmp->fd, tmp->data, BUF)))
	{
		if (rd == -1)
			return (-1);
		((char*)tmp->data)[rd] = '\0';
		if (check_endline(tmp, line))
			return (1);
	}
	return (0);
}