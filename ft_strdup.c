/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:50:48 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/01 21:51:47 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char	*dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t		len;
	char		*ptr;

	len = ft_strlen(src);
	ptr = (char *) malloc ((1 + len) * sizeof(char));
	if (!ptr)
		return (0);
	ft_strcpy(ptr, src);
	return (ptr);
}
