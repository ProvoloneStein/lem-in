/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:44:10 by pstein            #+#    #+#             */
/*   Updated: 2020/01/22 15:09:22 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		del_con(t_room *del_room, t_room *h_room)
{
	t_connect	*conn;
	t_connect	*head;
	t_connect	*conn1;

	conn = h_room->connect;
	if (conn->con_room == del_room)
	{
		h_room->connect = h_room->connect->next;
		free(conn);
		return (1);
	}
	head = h_room->connect;
	while (conn->next->con_room != del_room)
		conn = conn->next;
	if (conn->next->next)
	{
		conn1 = conn->next->next;
		free(conn->next);
		conn->next = conn1;
		return (1);
	}
	free(conn->next);
	conn->next = NULL;
	return (1);
}

void	make_wayname(char *name, t_way *way)
{
	t_names	*new_way;

	new_way = (t_names*)malloc(sizeof(t_names));
	new_way->name = name;
	new_way->next = way->mw;
	way->mw = new_way;
}

t_way	*mkway(int i)
{
	t_way *ways;

	ways = (t_way*)malloc(sizeof(t_way));
	ways->mw = NULL;
	if (i)
		ways->next = NULL;
	return (ways);
}

void	go_back(t_room *room, t_way *ways)
{
	int i;
	int j;

	i = 0;
	j = room->num_of_lem;
	while (room && room->last)
	{
		i++;
		room->v = 1;
		make_wayname(room->name, ways);
		del_con(room, room->last);
		room = room->last;
	}
	ways->len = i;
	if (j == i)
		ways->opt = i - 1;
	else
		ways->opt = i - ((i - j) / 2) - 1;
}
