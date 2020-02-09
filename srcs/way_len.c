/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:58:23 by pstein            #+#    #+#             */
/*   Updated: 2020/02/05 20:16:37 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		printway(t_way *way)
{
	t_way	*temp;
	t_names	*tempname;

	temp = way;
	while (way)
	{
		tempname = way->mw;
		ft_printf("\nway lenght = %i", way->len);
		ft_printf("\n{blue}========================================={eoc}\n");
		while (way->mw && way->mw->name)
		{
			ft_printf("%s ", way->mw->name);
			way->mw = way->mw->next;
		}
		ft_printf("\n{yellow}========================================={eoc}\n");
		way->mw = tempname;
		way = way->next;
	}
	way = temp;
}

int			ft_str_in(char *line, char *name)
{
	int j;
	int k;

	j = 1;
	while (line[j] && line[j - 1] == '-')
		j++;
	while (line[j - 1] != '-' && line[j])
		j++;
	k = 0;
	while (name[k] && line[k] == name[k])
		k++;
	if (name[k] == '\0' && line[k] == '-')
		return (1);
	k = 0;
	while (name[k] && line[j] == name[k])
	{
		j++;
		k++;
	}
	if (name[k] == '\0' && line[j] == '\0')
		return (1);
	return (0);
}

int			ft_bonus(t_way *way, int rnd, char **av, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		if (ft_strequ(av[i], "-w"))
			printway(way);
		else if (ft_strequ(av[i], "-r"))
			ft_printf("{red}====================={eoc}\nrounds = %i\n", rnd);
		i++;
	}
	return (1);
}

int			len_sort_1(t_way **way)
{
	t_way *dot;

	if (*way && (*way)->next && (*way)->len > (*way)->next->len)
	{
		dot = *way;
		*way = (*way)->next;
		dot->next = (*way)->next;
		(*way)->next = dot;
		return (1);
	}
	return (0);
}

t_way		*len_sort(t_way *way)
{
	t_way *head;
	t_way *dot;

	len_sort_1(&way);
	head = way;
	while (way && way->next && way->next->next)
	{
		if (len_sort_1(&head))
		{
			way = head;
			continue;
		}
		if (way->next->len > way->next->next->len)
		{
			dot = way->next;
			way->next = way->next->next;
			dot->next = way->next->next;
			way->next->next = dot;
			way = head;
			continue;
		}
		way = way->next;
	}
	way = head;
	return (head);
}
