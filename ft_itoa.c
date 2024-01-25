/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:04:45 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/03 18:52:52 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev_str(char *str, int len)
{
	int		i;
	char	swap;

	i = 0;
	while (i < len / 2)
	{
		swap = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = swap;
		i++;
	}
	return (str);
}

static int	ft_intlen(unsigned int c)
{
	int	len;

	len = 0;
	while (c >= 10)
	{
		len++;
		c /= 10;
	}
	return (len + 1);
}

static int	ft_check_pos(int c)
{
	if (c < 0)
		return (1);
	return (0);
}

void	ft_itoa2(char *str, unsigned int c, int len, int pos_neg)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = c % 10 + 48;
		c /= 10;
		i++;
	}
	if (pos_neg)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int c)
{
	int				len;
	char			*temp;
	int				i;
	unsigned int	save;
	int				pos_neg;

	i = 0;
	pos_neg = ft_check_pos(c);
	if (pos_neg)
		save = -c;
	else
		save = c;
	len = ft_intlen(save);
	temp = (char *)malloc(sizeof(char) * len + 1 + pos_neg);
	if (!temp)
		return (0);
	ft_itoa2(temp, save, len, pos_neg);
	return (rev_str(temp, len + pos_neg));
}
