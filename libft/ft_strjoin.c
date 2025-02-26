/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albbermu <albbermu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:09:52 by albbermu          #+#    #+#             */
/*   Updated: 2024/04/24 20:17:46 by albbermu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str_j;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str_j = malloc(sizeof(char) * (len + 1));
	if (!str_j)
		return (0);
	ft_strlcpy(str_j, s1, len + 1);
	ft_strlcat(str_j, s2, len + 1);
	return (str_j);
}
/*
int main(void) 
{
    char const *s1 = "Hello, ";
    char const *s2 = "World!";
    char const *s3 = "";
    char *result;

    result = ft_strjoin(s1, s2);
    if (result) {
        printf("Joined string: '%s'\n", result);
        free(result);
    }

    result = ft_strjoin(s3, s2);
    if (result) {
        printf("Joined string (one empty): '%s'\n", result);
        free(result);
    }

    result = ft_strjoin(s3, s3);
    if (result) {
        printf("Joined string (both empty): '%s'\n", result);
        free(result);
    }
    return 0;
}
*/
