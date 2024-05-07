/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:31:18 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/06 19:55:20 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

char	*ft_strdup1(char *s1)
{
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	str = (char *)malloc((ft_strlen1(s1) + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_substr1(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sublen;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	sublen = ft_strlen1(s) - start;
	if (sublen > len)
		sublen = len;
	str = (char *)malloc((sublen + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	while (s[start] && i < sublen)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
