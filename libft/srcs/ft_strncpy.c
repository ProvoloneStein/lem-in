/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:15:50 by pstein            #+#    #+#             */
/*   Updated: 2019/05/06 19:39:39 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (*src != '\0' && len > 0)
	{
		dst[i++] = *src++;
		len--;
	}
	while (len > 0)
	{
		dst[i++] = '\0';
		len--;
	}
	return (dst);
}
