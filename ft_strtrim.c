/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:53:38 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/02 18:56:24 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	remove_checker(const char *set, char c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_len(const char *str, const char *set, int start)
{
	int	i;
	int	len;
	int	second_i;

	i = 0;
	len = 0;
	second_i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	while (i > 0)
	{
		while (remove_checker(set, str[i]))
		{
			i--;
			second_i++;
		}
		break ;
	}
	return (len - second_i - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[i] != '\0' && remove_checker(set, s1[i]))
		i++;
	len = count_len(s1, set, i);
	return (ft_substr(s1, i, len + 1));
}
