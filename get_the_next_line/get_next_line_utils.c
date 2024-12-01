/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:15:18 by akella            #+#    #+#             */
/*   Updated: 2024/12/01 20:48:13 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = malloc((l1 + l2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < l2)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s)
		return (NULL);
	s1_len = ft_strlen(s);
	if (start >= s1_len)
		return (ft_strdup(""));
	s2_len = s1_len - start;
	if (s2_len > len)
		s2_len = len;
	s2 = malloc((s2_len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < s2_len && s[start + i])
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
