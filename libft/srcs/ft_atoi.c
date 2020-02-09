/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:13:30 by pstein            #+#    #+#             */
/*   Updated: 2020/02/05 20:07:17 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				i;
	long long int	result;
	long long int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i > 0 && str[i - 1] == '-')
		neg = -1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (result * neg);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		if ((result * neg) > 2147483647 || (result * neg) < -2147483648)
			return (-1);
		i++;
	}
	return (result * neg);
}

long long int		ft_atoi_long(const char *str)
{
	int				i;
	long long int	result;
	long long int	neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12 ||
			str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (result * neg);
		else
			result = (result * 10) + (long long int)(str[i] - '0');
		if ((result * neg) > 2147483647 || (result * neg) < -2147483648)
			return (-1);
		i++;
	}
	return (result * neg);
}
