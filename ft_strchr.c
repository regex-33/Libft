/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:49:04 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 18:59:07 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	b;

	i = 0;
	b = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == b)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == b)
		return ((char *)s + i);
	return (0);
}
