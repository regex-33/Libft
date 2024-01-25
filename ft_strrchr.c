/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:59:02 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 19:03:26 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	b;

	b = (char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == b)
			return ((char *)s + len);
		len--;
	}
	if (len == 0 && *s == b)
		return ((char *)s + len);
	return (0);
}
