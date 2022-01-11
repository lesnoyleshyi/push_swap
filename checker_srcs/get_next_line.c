/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:13:36 by stycho            #+#    #+#             */
/*   Updated: 2021/11/04 23:13:41 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	remainder = ft_upd_buf(remainder, fd);
	if (!remainder)
		return (NULL);
	line = ft_get_line(remainder);
	remainder = ft_remove_line(remainder);
	return (line);
}

char	*ft_upd_buf(char *buf, int fd)
{
	ssize_t	ret;
	char	temp_buf[BUFFER_SIZE + 1];
	char	*dummy_pointer;

	ret = 1;
	while (!ft_is_nl_here(buf) && ret > 0)
	{
		ret = read(fd, temp_buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		temp_buf[ret] = '\0';
		dummy_pointer = ft_strjoin_2(buf, temp_buf);
		free(buf);
		buf = dummy_pointer;
	}
	return (buf);
}

char	*ft_get_line(char *str)
{
	size_t	line_len;
	char	*line;
	int		i;

	line_len = 0;
	if (str[line_len] == '\0')
		return (NULL);
	while (str[line_len] != '\n')
	{
		if (str[line_len] == '\0')
			return (ft_strjoin_2("", str));
		line_len++;
	}
	line = (char *)malloc(line_len + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*ft_remove_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_remainder;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_remainder = (char *)malloc(ft_strlen(str + i) + 1);
	if (!new_remainder)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
		new_remainder[j++] = str[i++];
	new_remainder[j] = '\0';
	free(str);
	return (new_remainder);
}
