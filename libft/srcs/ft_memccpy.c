/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:45:53 by pstein            #+#    #+#             */
/*   Updated: 2019/05/06 19:20:30 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *strsrc;
	unsigned char *strdst;

	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	while (n > 0 && *strsrc != (unsigned char)c)
	{
		n--;
		*strdst++ = *strsrc++;
	}
	if (n > 0)
	{
		*strdst++ = *strsrc++;
		return (strdst);
	}
	else
		return (NULL);
}
