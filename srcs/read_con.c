/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_con.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:17:45 by pstein            #+#    #+#             */
/*   Updated: 2020/02/05 20:07:59 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_connect	*mk_con(t_room *rom, t_room *left)
{
	t_connect	*head;
	t_connect	*lst;

	lst = rom->connect;
	head = NULL;
	if (rom->connect)
	{
		head = rom->connect;
		while (lst && lst->next)
			lst = lst->next;
		lst->next = (t_connect*)malloc(sizeof(t_connect));
		lst->next->con_room = left;
		lst->next->next = NULL;
		return (head);
	}
	lst = (t_connect*)malloc(sizeof(t_connect));
	lst->con_room = left;
	lst->next = NULL;
	return (lst);
}

void		con_help(int *k, t_room **rt, t_room **lt, t_room *rm)
{
	if (*k == 0)
	{
		(*k)++;
		*lt = rm;
	}
	else if (*k == 1)
	{
		(*k)++;
		*rt = rm;
	}
}

int			connected(char *line, t_room *head)
{
	char	*name;
	t_room	*room;
	t_room	*right;
	t_room	*left;
	int		k;

	k = 0;
	room = head;
	name = line;
	while (room)
	{
		if (ft_str_in(line, room->name))
		{
			con_help(&k, &right, &left, room);
			if (k == 2)
			{
				right->connect = mk_con(right, left);
				left->connect = mk_con(left, right);
				return (1);
			}
		}
		room = room->next;
	}
	return (0);
}

int			line_checker_con(char *line, t_room *head)
{
	int	i;

	i = 0;
	while (line[i] == '-' && line[i])
		i++;
	while (line[i] != '-' && line[i])
		i++;
	if (line[i] == '-')
	{
		if (connected(line, head))
			return (1);
	}
	if (ft_strequ(line, "##start"))
		return (0);
	if (ft_strequ(line, "##end"))
		return (0);
	if (line[0] == '#' && line[1] == '#')
		return (2);
	if (line[0] == '#')
		return (2);
	return (0);
}

int			ft_connect_reader(int fd, t_room **room)
{
	char *line;

	while (get_next_line(fd, &line))
	{
		if (line_checker_con(line, *room))
		{
			ft_printf("%s\n", line);
			free(line);
		}
		else
			return (ft_free_room(line, *room));
	}
	return (1);
}
