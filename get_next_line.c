/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:04:24 by lyandriy          #+#    #+#             */
/*   Updated: 2022/11/12 12:49:52 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_txt(int fd, char *txt)
{
	char	*line;
	int		pos;
	int		i;

	pos = BUFFER_SIZE;
	i = -1;
	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i == -1 && pos != 0)
	{
		pos = read(fd, line, BUFFER_SIZE);
		if (pos == -1)
		{
			free(line);
			return (NULL);
		}
		line[pos] = '\0';
		txt = ft_strjoin(txt, line);
		i = ft_strchr(txt);
	}
	free(line);
	return (txt);
}

char	*ft_memcpy(char *txt)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!txt || txt[0] == '\0')
		return (NULL);
	while (txt[i] != '\0' && txt[i] != '\n')
		i++;
	if (txt[i] == '\n')
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (txt[i] != '\0' && txt[i] != '\n')
	{
		ptr[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_cpy(char *txt)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (txt[i] != '\0' && txt[i] != '\n')
		i++;
	if (txt[i] == '\0' || txt == NULL)
	{
		free(txt);
		return (NULL);
	}
	ptr = malloc ((ft_strlen(txt) - i) * sizeof(char));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	i++;
	while (txt[i] != '\0')
		ptr[j++] = txt[i++];
	ptr[j] = '\0';
	free(txt);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(txt);
		txt = NULL;
		return (NULL);
	}
	txt = get_txt(fd, txt);
	line = ft_memcpy(txt);
	txt = ft_cpy(txt);
	return (line);
}
