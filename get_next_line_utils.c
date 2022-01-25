/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:55:35 by mmartine          #+#    #+#             */
/*   Updated: 2022/01/25 18:51:50 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char		*destc;
	unsigned char		*srcc;
	int					i;

	destc = (unsigned char *)(dest);
	srcc = (unsigned char *)(src);
	i = n;
	if (dest == src || !n)
		return (dest);
	if (src < dest)
	{
		while (i-- > 0)
			destc[i] = srcc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			destc[i] = srcc[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		l1;
	int		l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((!s2 && !s1) || (l1 + l2) == 0)
		return (NULL);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_memmove(join, s1, l1);
	ft_memmove(join + l1, s2, l2);
	join[l1 + l2] = 0;
	free(s1);
	return (join);
}

int	search_lj(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_strlen(str) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
