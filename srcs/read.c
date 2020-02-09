/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 04:55:04 by pstein            #+#    #+#             */
/*   Updated: 2020/02/05 13:57:40 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_free_room(char *line, t_room *room)
{
	t_room		*head_r;
	t_connect	*head_c;

	if (line)
		free(line);
	while (room)
	{
		head_r = room->next;
		while (room->connect)
		{
			head_c = room->connect->next;
			free(room->connect);
			room->connect = head_c;
		}
		free(room->name);
		free(room);
		room = head_r;
	}
	return (-1);
}

int		first_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '#' && !(ft_strequ(line, "##start")
					|| ft_strequ(line, "##end")))
		{
			free(line);
			continue;
		}
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] || i == 0)
		{
			free(line);
			return (-1);
		}
		i = ft_atoi_long(line);
		ft_printf("%s\n", line);
		free(line);
		return (i);
	}
	return (-1);
}

char	*makename(char **l)
{
	char	*name;
	char	*line;
	int		len;

	line = *l;
	len = 0;
	while (!(line[len] == ' ' && isdigit(line[len + 1])))
		len++;
	name = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (!(line[len] == ' ' && isdigit(line[len + 1])))
	{
		name[len] = line[len];
		len++;
	}
	name[len] = '\0';
	while ((**l) != line[len])
		(*l)++;
	return (name);
}

void	makelst_hlp(t_room *lst)
{
	lst->metka = 0;
	lst->v = 0;
	lst->connect = NULL;
	lst->last = NULL;
	lst->is_start = 0;
	lst->is_end = 0;
	lst->num_of_lem = 2147483647;
}

t_room	*makelist(char *l, int *start, int *end)
{
	t_room	*lst;
	char	*line;

	line = l;
	if (!(lst = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	lst->name = makename(&line);
	lst->x = ft_atois(&line);
	lst->y = ft_atois(&line);
	makelst_hlp(lst);
	if (*start == 1)
	{
		lst->is_start = 1;
		(*start) = 2;
	}
	if (*end == 1)
	{
		lst->is_end = 1;
		(*end) = 2;
	}
	lst->next = NULL;
	return (lst);
}
