/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:31:42 by pstein            #+#    #+#             */
/*   Updated: 2020/01/26 17:38:30 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			way_count(t_way *way)
{
	t_way	*head;
	int		i;

	i = 1;
	head = way;
	while (way->next && way->next->opt)
	{
		i++;
		way = way->next;
	}
	way = head;
	return (i);
}

int			check_opt(t_way *way, int wtway)
{
	t_way	*head;
	int		i;
	int		j;

	i = wtway - 1;
	head = way;
	while (i)
	{
		i--;
		way = way->next;
	}
	if (way->next)
		j = way->opt - way->next->opt;
	else
		j = way->opt;
	way = head;
	return (j);
}

static int	round_help(t_way *way, int *an_ro, int i, int *waycount)
{
	int	step;

	*an_ro = *an_ro - i / *waycount;
	(*waycount)--;
	while (!(step = check_opt(way, *waycount) * *waycount) && *waycount > 1)
		(*waycount)--;
	*an_ro = *an_ro + i / *waycount;
	return (step);
}

int			print_round(t_way *way, int count, int r, int way_c)
{
	t_way	*wave;
	int		i;
	int		j;
	int		k;
	int		step;

	i = 0;
	j = 0;
	k = 0;
	step = check_opt(way, way_c) * way_c;
	while (i < count)
	{
		if (!(step) && way_c > 1 && (step = round_help(way, &r, i, &way_c)))
			k = i % way_c;
		step--;
		if (!(wave = find_way(way, way_c, i - k, r)))
		{
			if (++j == count)
				return (0);
		}
		else
			ft_printf("L%i-%s ", i + 1, find_name(wave, i - k, way_c, r)->name);
		i++;
	}
	return (1);
}

int			doit(t_way *way, int count)
{
	int	round;
	int	wayuse;

	round = 1;
	if (count)
	{
		opt_alg(way, count);
		wayuse = way_count(way);
		while (print_round(way, count, round, wayuse))
		{
			write(1, "\n", 1);
			round++;
		}
	}
	return (round);
}
