/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:58:38 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/02 18:59:09 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	abs;
	char	*temp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	abs = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	if (abs < len)
		temp = (char *)malloc(sizeof(char) * (abs + 1));
	else
		temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (i < len && start + i < ft_strlen(s))
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
