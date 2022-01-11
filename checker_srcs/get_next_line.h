/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:43:29 by stycho            #+#    #+#             */
/*   Updated: 2021/11/04 23:43:33 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 256

char	*get_next_line(int fd);
char	*ft_upd_buf(char *buf, int fd);
char	*ft_get_line(char *str);
char	*ft_remove_line(char *str);
int		ft_is_nl_here(char *str);
char	*ft_strjoin_2(char *str1, char *str2);
size_t	ft_strlen(const char *s);

#endif
