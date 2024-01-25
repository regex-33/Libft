/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachtata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:38:09 by yachtata          #+#    #+#             */
/*   Updated: 2023/11/02 18:38:58 by yachtata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	int	num;

	num = nb;
	if (nb == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		write(fd, "147483648", 9);
	}
	else if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
		ft_putnbr(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
	else
		ft_putchar(nb + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	ft_putnbr(n, fd);
}
