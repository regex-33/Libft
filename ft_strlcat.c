/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:38:46 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 19:00:32 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	len_src = ft_strlen(src);
	if ((!dest && size == 0) || (dest == src))
		return (len_src);
	len_dest = ft_strlen(dest);
	if (size == 0 || len_dest >= size)
		return (len_src + size);
	i = 0;
	while (src[i] != '\0' && i + len_dest < size - 1)
	{
		dest[len_dest + i] = src[i];
		++i;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
