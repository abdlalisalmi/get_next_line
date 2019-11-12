/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-salm <aes-salm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:48:58 by aes-salm          #+#    #+#             */
/*   Updated: 2019/11/12 14:05:45 by aes-salm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	char	*pstr;
	int		i;

	pstr = (char*)str;
	i = 0;
	while (pstr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char **line, char *tmp)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	line_len;
	unsigned int	tmp_len;

	if (!*line && tmp)
		return (ft_strdup(tmp));
	line_len = ft_strlen(*line);
	tmp_len = ft_strlen(tmp);
	if (!(new_str = malloc(line_len + tmp_len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < line_len)
	{
		new_str[i] = line[0][i];
		i++;
	}
	while (j < tmp_len)
		new_str[i++] = tmp[j++];
	new_str[i] = '\0';
	free_all(line);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		s_len;

	if (!s || !(sub = malloc(len + 1)))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while (s[i] != '\0' && i < len && start < s_len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

void	free_all(char **var)
{
	free(*var);
	*var = NULL;
}
