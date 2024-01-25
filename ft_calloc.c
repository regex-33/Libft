/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:02:39 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 18:50:57 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			len;
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	len = count * size;
	temp = (unsigned char *)malloc(len);
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}
