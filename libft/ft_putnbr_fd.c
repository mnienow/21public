/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:45:42 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/06 15:45:44 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb <= 9 && nb * (-1) <= 9)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = nb * -1;
		}
		ft_putchar_fd(nb + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		if (nb < 0)
			nb = nb * -1;
		ft_putnbr_fd(nb % 10, fd);
	}
}
