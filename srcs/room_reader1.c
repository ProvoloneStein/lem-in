/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_reader1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 05:22:32 by pstein            #+#    #+#             */
/*   Updated: 2020/02/05 20:08:40 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_room(t_room *room)
{
	t_room		*head_r;
	t_connect	*head_c;

	while (room)
	{
		head_r = room->next;
		while (room->connect)
		{
			head_c = room->connect->next;
			free(room->connect);
			room->connect = head_c;
		}
		free(room->name);
		free(room);
		room = head_r;
	}
}

int		check_cord(char *str, int i)
{
	int	j;
	int k;

	k = -1;
	j = i;
	if (ft_atoi_long(str + i) != ft_atoi(str + i))
		return (0);
	if (str[j] == '-' || str[j] == '+')
	{
		j++;
		k = j;
	}
	while (ft_isdigit(str[j]))
		j++;
	if (k == j)
		return (0);
	return (j);
}

int		is_room(char *str)
{
	int		i;
	int		k;

	i = 0;
	if (str[i] != 'L' && str[i] != '#' && str[i] >= 33 && str[i] <= 126)
		i++;
	while (str[i] >= 33 && str[i] <= 126)
		i++;
	if (i && str[i] == ' ')
	{
		k = ++i;
		if ((i = check_cord(str, i)))
			if (i == k)
				return (0);
		if (str[i] == ' ')
		{
			k = ++i;
			if ((i = check_cord(str, i)))
				if (k != i && (str[i] == '\n' || str[i] == '\0'))
					return (1);
		}
	}
	return (0);
}
