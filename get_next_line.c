/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:55:13 by mmartine          #+#    #+#             */
/*   Updated: 2022/01/25 18:53:09 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
{
	char	*ret;
	int		lj;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	lj = search_lj(str);
	if (lj == -1)
		lj = ft_strlen(str);
	else if (str[lj] == '\n')
		lj += 1;
	ret = (char *)malloc(lj + 1);
	if (!ret)
		return (NULL);
	while (i < lj)
	{
		ret[i] = str[i];
		i++;
	}
	ret[lj] = '\0';
	return (ret);
}

static char	*get_sta(char *str)
{
	char	*ret;
	int		start;
	int		i;
	int		strlen;

	i = -1;
	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	start = search_lj(str);
	if (start == -1)
		start = ft_strlen(str);
	else if (str[start] == '\n')
		start += 1;
	ret = (char *)malloc(strlen - start + 1);
	if (!ret)
		return (NULL);
	while (++i < (strlen - start))
		ret[i] = str[i + start];
	ret[i] = '\0';
	free(str);
	if (*ret)
		return (ret);
	free(ret);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*line;
	int			re;

	re = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc (BUFFER_SIZE + 1);
	while (re && search_lj(sta) == -1)
	{
		re = read(fd, line, BUFFER_SIZE);
		if (re < 0)
		{
			free(line);
			return (NULL);
		}
		line[re] = '\0';
		sta = ft_strjoin(sta, line);
	}
	free(line);
	line = get_line(sta);
	sta = get_sta(sta);
	return (line);
}
