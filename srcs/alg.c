/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:46:56 by pstein            #+#    #+#             */
/*   Updated: 2020/01/22 16:47:45 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_end(t_room *room)
{
	while (room)
	{
		if (room->is_end && room->last)
			return (room);
		room = room->next;
	}
	return (NULL);
}

static int	check_new1(t_way *new, int opt, int count, int way_c)
{
	int i;
	int j;

	if ((opt + count) % way_c)
		i = (opt + count) / way_c + 1;
	else
		i = (opt + count) / way_c;
	if ((opt + count + new->len - 1) % (way_c + 1))
		j = (opt + count + new->opt) / (way_c + 1) + 1;
	else
		j = (opt + count + new->opt) / (way_c + 1);
	if (i < j)
		return (1);
	return (0);
}

int			check_new(t_way *way, t_way *new, int count)
{
	t_way	*head;
	int		opt;
	int		way_c;

	way_c = 0;
	opt = 0;
	head = way;
	while (way)
	{
		opt += way->len - 1;
		way_c++;
		way = way->next;
	}
	way = head;
	return (check_new1(new, opt, count, way_c));
}

int			ft_start(t_room *h_room, t_way **way, int count)
{
	t_room		*room;
	t_way		*ways;

	room = h_room;
	while (room && !(room->is_start))
		room = room->next;
	if (!(room) || !(room->connect))
		return (0);
	room->num_of_lem = 0;
	while (itteration(h_room))
		continue;
	if (!(room = find_end(h_room)))
		return (0);
	ways = mkway(1);
	go_back(room, ways);
	if (*way && check_new(*way, ways, count))
	{
		free_way(ways);
		return (0);
	}
	make_way(way, ways);
	clean_len(h_room);
	return (1);
}
