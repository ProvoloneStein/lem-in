/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:27:57 by pstein            #+#    #+#             */
/*   Updated: 2020/01/20 21:22:15 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_names		*find_name(t_way *way, int i, int waycount, int round)
{
	t_names	*head;
	t_names	*mem;
	int		j;
	int		nol;

	head = way->mw;
	mem = way->mw;
	if (i)
		nol = i / waycount;
	else
		nol = 0;
	j = round - 1 - nol;
	while (j)
	{
		mem = mem->next;
		j--;
	}
	way->mw = head;
	return (mem);
}

t_way		*find_way(t_way *way, int waycount, int i, int round)
{
	t_way	*head;
	t_way	*mem;
	int		j;

	head = way;
	mem = way;
	j = i % waycount;
	while (j)
	{
		mem = mem->next;
		j--;
	}
	if (i)
		j = i / waycount;
	else
		j = 0;
	if (round <= j || round > mem->len + j)
	{
		way = head;
		return (NULL);
	}
	way = head;
	return (mem);
}

static void	count_helper(t_way *way, t_way *ravn)
{
	while (way && way->next)
	{
		if (way->next && (way->len == way->next->len) && ravn->len != way->len)
		{
			ravn = way;
			while (way->next && (way->len == way->next->len))
			{
				if (way->opt < way->next->opt)
				{
					way->opt++;
					way->next->opt--;
					way = ravn;
				}
				else
					way = way->next;
			}
			way = ravn;
		}
		way->opt = way->opt - way->len + 1;
		way = way->next;
		if (!(way->next))
			way->opt = way->opt - way->len + 1;
	}
}

int			countcheck(t_way *way)
{
	t_way *head;
	t_way *ravn;

	head = way;
	ravn = way;
	count_helper(way, ravn);
	way = head;
	return (way->opt + way->len + 1);
}

int			opt_alg(t_way *way, int count)
{
	t_way	*head;

	head = way;
	way->opt = way->opt + count;
	while (way && way->next)
	{
		if (way->opt > way->next->opt)
		{
			way->opt--;
			way->next->opt++;
			way = head;
			continue;
		}
		way = way->next;
	}
	way = head;
	return (countcheck(way));
}
