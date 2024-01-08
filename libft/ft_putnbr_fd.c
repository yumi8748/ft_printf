/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:59:41 by yu-chen           #+#    #+#             */
/*   Updated: 2023/11/17 20:36:49 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	digit = '0' + n % 10;
	ft_putchar_fd(digit, fd);
}
