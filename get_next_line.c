/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:27:55 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/23 19:21:12 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(char **line, char **text, int fd, int num_read_char)
{
	int		len;
	char	*tmp;

	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(text[fd] + len + 1);
		free(text[fd]);
		text[fd] = tmp;
		if (text[fd][0] == '\0')
			ft_strdel(&text[fd]);
	}
	else if (text[fd][len] == '\0')
	{
		if (num_read_char == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*text[MAX_FD];
	char			*tmp;
	int				num_read_char;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((num_read_char = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[num_read_char] = '\0';
		if (text[fd] == NULL)
			text[fd] = ft_strnew(1);
		tmp = ft_strjoin(text[fd], buf);
		free(text[fd]);
		text[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (num_read_char < 0)
		return (-1);
	else if (num_read_char == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (new_line(line, text, fd, num_read_char));
}
