/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:41:46 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/01 20:43:19 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*destt;

	i = 0;
	temp = (unsigned char *)src;
	destt = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		destt[i] = temp[i];
		i++;
	}
	return (destt);
}
