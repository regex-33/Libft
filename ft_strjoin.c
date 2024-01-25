/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:53:09 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/02 10:54:08 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *dest, const char *src)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		++i;
	}
	dest[len + i] = '\0';
}

static void	ft_strcpy(char	*dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

static char	*ft_strjoin_part2(const char *s1, const char *s2, char **dest)
{
	int	len_s1;
	int	len_s2;

	if (!s1)
	{
		len_s2 = ft_strlen(s2);
		*dest = (char *)malloc(sizeof(char) * len_s2 + 1);
		if (!dest)
			return (NULL);
		ft_strcpy(*dest, s2);
	}
	else
	{
		len_s1 = ft_strlen(s1);
		*dest = (char *)malloc(sizeof(char) * len_s1 + 1);
		if (!*dest)
			return (NULL);
		ft_strcpy(*dest, s1);
	}
	return (*dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * len_s1 + len_s2 + 1);
		if (!dest)
			return (0);
		ft_strcpy(dest, s1);
		ft_strcat(dest, s2);
	}
	else
	{
		if (!ft_strjoin_part2(s1, s2, &dest))
			return (NULL);
	}
	return (dest);
}
