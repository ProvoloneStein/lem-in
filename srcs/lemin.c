/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:54:41 by pstein            #+#    #+#             */
/*   Updated: 2020/01/26 17:58:39 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			make_opt(t_way *way)
{
	t_way *head;

	head = way;
	while (way)
	{
		way->opt = way->len - 1;
		way = way->next;
	}
	way = head;
	return (1);
}

int			ft_reader(int *count, int ac, char **av, t_room **room)
{
	int		fd;

	fd = 0;
	if (ac >= 2 && av[1][0] != '-')
		fd = open(av[1], O_RDONLY);
	if ((*count = first_line(fd)) < 0)
		return (-ft_printf("Error\n"));
	if (room_reader(fd, room) == -1)
		return (-ft_printf("Error\n"));
	if (ft_connect_reader(fd, room) == -1)
		return (-ft_printf("Error\n"));
	if (fd != 0)
		close(fd);
	return (1);
}

void		free_way(t_way *way)
{
	t_way	*head_w;
	t_names	*head_n;

	while (way)
	{
		head_w = way->next;
		while (way->mw)
		{
			head_n = way->mw->next;
			free(way->mw);
			way->mw = head_n;
		}
		free(way);
		way = head_w;
	}
}

t_way		*ways_fix(t_way *way)
{
	check_perecos(way);
	way = len_sort(way);
	make_opt(way);
	return (way);
}

int			main(int ac, char **av)
{
	t_way	*way;
	int		count;
	t_room	*room;
	int		i;

	way = NULL;
	room = NULL;
	if (ft_reader(&count, ac, av, &room) != 1)
		return (0);
	while (ft_start(room, &way, count))
		check_perecos(way);
	if (way)
	{
		way = ways_fix(way);
		i = doit(way, count) - 1;
		if (ac >= 2)
			ft_bonus(way, i, av, ac);
		free_way(way);
		free_room(room);
		return (1);
	}
	free_room(room);
	ft_printf("No possible solution\n");
	return (0);
}
