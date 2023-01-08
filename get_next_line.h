/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:53 by lyandriy          #+#    #+#             */
/*   Updated: 2022/11/11 20:33:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_memcpy(char *txt);
char	*ft_cpy(char *txt);
char	*get_txt(int fd, char *txt);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_strchr(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif