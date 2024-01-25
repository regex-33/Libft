/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:26:38 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/05 10:47:31 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_strings(char *str, char charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != charset)
			i++;
	}
	return (count);
}

static int	ft_sep_len(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != charset)
		i++;
	return (i);
}

static char	*ft_word(char *str, char charset, char **head, int b)
{
	int		i;
	char	*save;
	int		len;

	i = 0;
	len = ft_sep_len(str, charset);
	save = (char *) malloc (sizeof(char) * (len + 1));
	if (!save)
	{
		if (b)
		{
			while (i < b)
				free (head[i++]);
		}
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	**ft_split_helper(char *str, char charset, char **temp, int *i)
{
	while (*str != '\0')
	{
		while (*str != '\0' && *str == charset)
			str++;
		if (*str != '\0')
		{
			temp[*i] = ft_word(str, charset, temp, *i);
			if (!temp[*i])
			{
				free(temp);
				return (NULL);
			}
			(*i)++;
		}
		while (*str != '\0' && *str != charset)
			str++;
	}
	return (temp);
}

char	**ft_split(char *str, char charset)
{
	int		i;
	char	**temp;

	i = 0;
	if (!str)
		return (NULL);
	temp = (char **)malloc((number_strings(str, charset) + 1) * sizeof(char *));
	if (!temp)
		return (0);
	temp = ft_split_helper(str, charset, temp, &i);
	if (!temp)
		return (NULL);
	temp[i] = 0;
	return (temp);
}
