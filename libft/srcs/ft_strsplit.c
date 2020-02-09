/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:19:56 by pstein            #+#    #+#             */
/*   Updated: 2019/05/06 21:16:09 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_count(const char *str, char seps)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_next(str, seps, 0);
		}
	}
	return (i);
}

static char			**ft_delka(char **bl, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(bl[i]);
	free(bl);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**bl;
	int			i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	if (!(bl = (char**)malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_next(s, c, 0);
			bl[i] = ft_strsub(s, 0, next - s);
			if (bl[i] == NULL)
				return (ft_delka(bl, i));
			i++;
			s = next;
		}
	}
	bl[i] = 0;
	return (bl);
}
