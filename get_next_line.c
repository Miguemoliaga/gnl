#include "get_next_line.h"

char	*multifunctcpy(char *buff, char *str, int start, int end)
{
	char	*aux;
	char	*bufsplit;

	bufsplit = ft_substr(buff, start, end);
	aux = str;
	str = ft_strjoin(aux, bufsplit);
	free(bufsplit);
	return (str);
}

char	*strtreat(char *str, int fd)
{
	int		lj;
	int		re;
	char	*buff;

	lj = -1;
	re = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	re = read(fd, buff, BUFFER_SIZE);
	while (lj == -1 && re != 0)
	{
		lj = search_lj(buff);
		str = multifunctcpy(buff, str, 0, BUFFER_SIZE);
		re = read(fd, buff, BUFFER_SIZE);
		if (re == 0)
			return (str);
	}
	if (re == 0)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	int			linelj;

	str = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = "";
	linelj = search_lj(line);
	if (linelj != -1)
	{
		str = ft_substr(line, 0, linelj);
		line = ft_substr(line, linelj + 1, BUFFER_SIZE);
	}
	else
	{
		str = ft_strdup(line);
		str = strtreat(str, fd);
		if (!str)
			return (NULL);
		line = ft_substr(str, search_lj(str) + 1, BUFFER_SIZE);
		str = ft_substr(str, 0, search_lj(str));
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
