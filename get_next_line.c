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
/*
char	*strtreat(char *line, char *str, int fd)
{
	int		size;
	int		re;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	size = 1;
	while (size)
	{
		re = read(fd, buff, BUFFER_SIZE);
		if (re <= 0)
			return (NULL);
		size = search_lj(buff);
		if (size == -1)
			str = multifunctcpy(buff, str, 0, BUFFER_SIZE);
		else
		{
			str = multifunctcpy(buff, str, 0, size);
			line = multifunctcpy(buff, line, size + 1, BUFFER_SIZE);
			printf("line vale %s\n", line);
			size = 0;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;
	int			linelj;

	ret = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = "";
	linelj = search_lj(line);
	if (linelj != -1)
	{
		ret = ft_substr(line, 0, linelj);
		line = ft_substr(line, linelj + 1, BUFFER_SIZE);
	}
	else
	{
		printf("antes de volcar line en ret, line vale: %s\n", line);
		ret = ft_strdup(line);
		line = "";
		printf("despues de volcar  line en ret, ret vale: %s y line vale: %s\n", ret, line);
		ret = strtreat(line, ret, fd);
	}
	return (ret);
}
*/
	//problemas al hacer cosas con line, no estamos guardando el valor adecuado.

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret;
	int			linelj;
	int			re;

	ret = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = "";
	linelj = search_lj(line);
	if (linelj != -1)
	{
		ret = ft_substr(line, 0, linelj);
		line = ft_substr(line, linelj + 1, BUFFER_SIZE);
	}
	else
	{
		
	}
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("filex.txt", O_RDONLY);
	while (i++ < 9)
	{
		str = get_next_line(fd);
		printf("%s\n", str);
	}
}
