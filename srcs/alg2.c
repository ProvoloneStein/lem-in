/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:18:01 by pstein            #+#    #+#             */
/*   Updated: 2020/01/22 14:36:02 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_way(t_way **way, t_way *end)
{
	t_way	*go;

	if (!(*way))
		(*way) = end;
	else
	{
		go = (*way);
		while (go && go->next)
			go = go->next;
		go->next = end;
		go->next->next = NULL;
	}
}

int		check_have_con(t_room *r1, char *name)
{
	t_connect	*head;

	if (r1->connect)
	{
		head = r1->connect;
		while (r1->connect)
		{
			if (ft_strequ(r1->connect->con_room->name, name))
			{
				r1->connect = head;
				return (1);
			}
			r1->connect = r1->connect->next;
		}
		r1->connect = head;
	}
	return (0);
}

void	makepod(t_room *room)
{
	t_room		*r;
	t_connect	*head;

	r = room;
	head = r->connect;
	while (r->connect)
	{
		if (!(r->connect->con_room->metka))
		{
			if (r->connect->con_room->num_of_lem > r->num_of_lem + 1)
			{
				r->connect->con_room->last = r;
				if (check_have_con(r->connect->con_room, r->name))
				{
					if (!(!(r->connect->con_room->v) && r->v && !(r->last->v)))
						r->connect->con_room->num_of_lem = r->num_of_lem + 1;
				}
				else
					r->connect->con_room->num_of_lem = r->num_of_lem - 1;
			}
		}
		r->connect = r->connect->next;
	}
	r->connect = head;
	r->metka = 1;
}

int		itteration(t_room *room)
{
	t_room	*step;
	t_room	*i;

	step = room;
	i = room;
	while (step)
	{
		if (!(step->metka) && (i->metka || step->num_of_lem < i->num_of_lem))
			i = step;
		step = step->next;
	}
	if (i->metka || i->num_of_lem == 2147483647)
		return (0);
	makepod(i);
	return (1);
}

void	clean_len(t_room *room)
{
	t_room	*step;

	step = room;
	while (step)
	{
		step->metka = 0;
		step->last = NULL;
		step->num_of_lem = 2147483646;
		step = step->next;
	}
}
