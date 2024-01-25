/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:45:28 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/02 18:46:41 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*temp;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (s[i] != '\0')
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
