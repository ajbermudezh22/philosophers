/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:45:56 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/25 14:59:22 by albbermu         ###   ########.fr       */
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
