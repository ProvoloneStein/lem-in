/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:43:25 by pstein            #+#    #+#             */
/*   Updated: 2020/02/08 21:43:31 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_duplicates(t_room **room)
{
	t_room *ref;
	t_room *temp;

	ref = (*room)->next;
	temp = *room;
	if (temp == 0)
		return (0);
	while (temp->next)
	{
		while (ref)
		{
			if (ft_strequ(temp->name, ref->name))
				return (0);
			ref = ref->next;
		}
		temp = temp->next;
		if (temp->next)
			ref = temp->next;
	}
	return (1);
}
