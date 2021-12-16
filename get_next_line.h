#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, int len);
int		search_lj(char *str);
char	*ft_strdup(char *s);

#endif
