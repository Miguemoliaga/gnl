#include "get_next_line.h"

static int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1c;
	unsigned char	*str2c;

	str1c = (unsigned char *)str1;
	str2c = (unsigned char *)str2;
	while (0 < n)
	{
		if (*str1c != *str2c)
			return (*str1c - *str2c);
		n--;
		str1c++;
		str2c++;
	}
	return (0);
}

static char	*multifunctcpy(char *buff, char *str, int start, int end)
{
	char	*bufsplit;

	bufsplit = ft_substr(buff, start, end);
	str = ft_strjoin(str, bufsplit);
	free(bufsplit);
	return (str);
}

static char	*strtreat(char *str, int fd, char *line)
{
	int		lj;
	int		re;
	char	*buff;

	lj = -1;
	re = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	str = ft_strdup(line);
	while (lj == -1 && re != 0)
	{
		re = read(fd, buff, BUFFER_SIZE);
		if (re == 0)
			return (str);
		lj = search_lj(buff);
		if (lj == -2)
			break ;
		str = multifunctcpy(buff, str, 0, re);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	int			linelj;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	linelj = search_lj(line);
	if (linelj > -1)
	{
		str = ft_substr(line, 0, linelj);
		line = ft_substr(line, linelj + 1, BUFFER_SIZE);
	}
	else if (linelj <= -1)
	{
		str = strtreat(str, fd, line);
		line = ft_substr(str, search_lj(str) + 1, BUFFER_SIZE);
		str = ft_substr(str, 0, search_lj(str));
		if (ft_memcmp(str, line, ft_strlen(str)) == 0)
		{	
			line = NULL;
			return (NULL);
		}
	}
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("filex.txt", O_RDONLY);
	while (i++ < 10)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
}
