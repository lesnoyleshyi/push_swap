/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:12:49 by stycho            #+#    #+#             */
/*   Updated: 2021/11/04 23:12:57 by stycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_is_nl_here(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_2(char *str1, char *str2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;
	char	*res_start;

	len_s1 = 0;
	if (str1 != NULL)
		len_s1 = ft_strlen(str1);
	len_s2 = ft_strlen(str2);
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res_start = res;
	while (len_s1--)
		*res++ = *str1++;
	while (len_s2--)
		*res++ = *str2++;
	*res = '\0';
	return (res_start);
}
