/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:19:34 by pstein            #+#    #+#             */
/*   Updated: 2020/01/23 16:39:06 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char		*ft_dupflex(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	if ((result = ft_strnew(n)))
	{
		i = 0;
		while (i < n)
		{
			result[i] = s[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

int			ft_make_line(char **line, char *content)
{
	int		i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!(*line = ft_dupflex(content, i)))
		return (0);
	return (i);
}

int			ft_readfile(const int fd, char **content)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		tmp = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (i);
}

t_list		*get_list_number(int fd, t_list **hist)
{
	t_list	*tmp;

	if (!hist)
		return (NULL);
	tmp = *hist;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(hist, tmp);
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			read_result;
	static t_list	*hist;
	t_list			*live;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buf, 0)) < 0 ||
			(!(live = get_list_number(fd, &hist))))
		return (-1);
	tmp = live->content;
	read_result = ft_readfile(fd, &tmp);
	live->content = tmp;
	if (!read_result && !*tmp)
		return (0);
	read_result = ft_make_line(line, live->content);
	tmp = live->content;
	if (tmp[read_result] != '\0')
	{
		live->content = ft_strdup(&((live->content)[read_result + 1]));
		free(tmp);
	}
	else
		tmp[0] = '\0';
	return (1);
}
