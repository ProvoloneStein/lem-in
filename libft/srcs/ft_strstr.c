/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:33:04 by pstein            #+#    #+#             */
/*   Updated: 2019/05/06 20:56:14 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *s1_it;
	const char *s2_it;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		s1_it = haystack;
		s2_it = needle;
		while (*s2_it != '\0' && *s1_it == *s2_it)
		{
			s1_it++;
			s2_it++;
		}
		if (*s2_it == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
