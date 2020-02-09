/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:54:49 by pstein            #+#    #+#             */
/*   Updated: 2020/02/08 21:37:58 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			line_checker(char *line, int *start, int *end)
{
	int	i;

	i = 0;
	if (is_room(line))
		return (1);
	if (ft_strequ(line, "##start"))
	{
		if (*end == 1 || *start == 2)
			return (-1);
		(*start) = 1;
		return (2);
	}
	if (ft_strequ(line, "##end"))
	{
		if (*start == 1 || *end == 2)
			return (-1);
		(*end) = 1;
		return (2);
	}
	if (line[i] == '#')
		return (0);
	return (-1);
}

int			one_rm_rd(int fd, int *start, int *end, t_room **room)
{
	char	*line;
	int		i;

	line = NULL;
	while (*room == NULL && get_next_line(fd, &line))
	{
		if ((i = line_checker(line, start, end)) >= 0)
		{
			if (i == 1)
				*room = makelist(line, start, end);
			if (i >= 1)
				ft_printf("%s\n", line);
			free(line);
		}
		else
		{
			free(line);
			return (-1);
		}
	}
	return (1);
}

int			other_helper(char *line, t_room *room, int i)
{
	if (i == 4 && line_checker_con(line, room))
	{
		ft_printf("%s\n", line);
		free(line);
		return (1);
	}
	ft_free_room(line, room);
	return (-1);
}

int			else_rm_rd(int fd, int *start, int *end, t_room *room)
{
	int		i;
	char	*line;
	t_room	*head;

	head = room;
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if ((i = line_checker(line, start, end)) >= 0)
		{
			if (i == 1)
				room->next = makelist(line, start, end);
			if (i >= 1)
				ft_printf("%s\n", line);
			free(line);
		}
		else
		{
			room = head;
			return (other_helper(line, room, *start + *end));
		}
		if (room->next)
			room = room->next;
	}
	return (ft_free_room(NULL, head));
}

int			room_reader(int fd, t_room **room)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (one_rm_rd(fd, &start, &end, room) == -1)
		return (-1);
	if (else_rm_rd(fd, &start, &end, *room) == -1)
		return (-1);
	if (!(find_duplicates(room)))
	{
		free_room(*room);
		return (-1);
	}
	return (1);
}
