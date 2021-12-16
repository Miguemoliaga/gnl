#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
int		search_lj(char *str);
char	*ft_strdup(const char *s);

#endif
