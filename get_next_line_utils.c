/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikoubaz <yikoubaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:42:39 by yikoubaz          #+#    #+#             */
/*   Updated: 2025/11/10 18:28:23 by yikoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strcat(char *dst, char *src)
{
	size_t	d_len;
	size_t	i;

	d_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (dst);
}

char	*ft_strdup(char	*s)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	len = 0;
	while (s[i])
		new[len++] = s[i++];
	new[len] = 0;
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (i < s1_len)
	{
		new[i] = s1[i];
		i++;
	}
	free(s1);
	new[i] = 0;
	new = ft_strcat(new, s2);
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}
