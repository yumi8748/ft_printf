/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:05:06 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/04 19:55:53 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	unsigned long	nb;
	size_t			len;
	int				base_len;
	char			*res;

	nb = n;
	len = n == 0;
	base_len = ft_strlen(base);
	while (n != 0)
	{
		len++;
		n /= ft_strlen(base);
	}
	res = ft_calloc(len + 1, 1);
	if (!res)
		return (NULL);
	*res = *base;
	while (nb)
	{
		res[len - 1] = base[nb % base_len];
		len--;
		nb /= base_len;
	}
	return (res);
}
