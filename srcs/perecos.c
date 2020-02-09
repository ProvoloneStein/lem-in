/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perecos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 22:16:48 by pstein            #+#    #+#             */
/*   Updated: 2020/01/22 17:25:30 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		sv_a(t_names *w_name, t_way *a)
{
	w_name->next = a->mw->next->next;
	return (0);
}

int		c_ln(t_way *k1, t_way *k2, int i, int j)
{
	int mem;

	if (k1->mw->next)
		free(k1->mw->next);
	k1->mw->next = k2->mw->next;
	free(k2->mw);
	mem = k1->len;
	k1->len = k2->len + i - j;
	k2->len = mem + j - i - 2;
	return (0);
}

int		v_hd(t_way *k1, t_way *k2, t_names *hd1, t_names *hd2)
{
	k1->mw = hd1;
	k2->mw = hd2;
	return (0);
}

int		perecos(t_way *a, t_way *b)
{
	t_names	*h1;
	t_names	*h2;
	t_names	*k;
	int		i;
	int		j;

	i = 0;
	h1 = a->mw;
	h2 = b->mw;
	while (a->mw)
	{
		i++;
		b->mw = h2;
		j = 0;
		while (b->mw)
		{
			j++;
			if (j > 1 && ft_strequ(a->mw->name, b->mw->name) && (a->mw->next))
				return (1 + sv_a(k, a) + c_ln(a, b, i, j) + v_hd(a, b, h1, h2));
			k = b->mw;
			b->mw = b->mw->next;
		}
		a->mw = a->mw->next;
	}
	return (v_hd(a, b, h1, h2));
}

void	*check_perecos(t_way *way)
{
	t_way *k1;
	t_way *k2;

	k1 = way;
	while (k1)
	{
		k2 = k1->next;
		while (k2)
		{
			if (perecos(k1, k2))
			{
				k1 = way;
				k2 = k1->next;
			}
			else
				k2 = k2->next;
		}
		k1 = k1->next;
	}
	return (NULL);
}
