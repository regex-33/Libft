/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:49:56 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 19:01:06 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(needle);
	if (n == 0 && len > 0)
		return (0);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + len <= n)
	{
		if (haystack[i] == needle[0])
		{
			j = ft_strncmp(haystack + i, needle, len);
			if (j == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
