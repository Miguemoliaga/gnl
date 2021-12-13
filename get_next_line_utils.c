#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	int		i;
	int		j;
	int		s2len;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	s2len = ft_strlen(s2);
	news = (char *)malloc((ft_strlen(s1) + s2len + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (i < ft_strlen(s1) && s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	while (j < s2len && s2[j])
	{
		news[i + j] = s2[j];
		j++;
	}
	news[i + j] = '\0';
	return (news);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(s);
	p = malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (i < (len * sizeof(char)))
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

int	search_lj(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
