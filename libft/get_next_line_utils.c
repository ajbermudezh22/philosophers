/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:23:54 by albbermu          #+#    #+#             */
/*   Updated: 2024/05/22 15:10:29 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s1(char *s1, const char *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_s1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

char	*ft_strdup(const char *str1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(str1);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
