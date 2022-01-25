/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:55:01 by mmartine          #+#    #+#             */
/*   Updated: 2022/01/25 17:41:14 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
//# define BUFFER_SIZE 1000000

char	*get_next_line(int fd);
int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2);
int		search_lj(char *str);

#endif