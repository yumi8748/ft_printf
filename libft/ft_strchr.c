/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:14:51 by yu-chen           #+#    #+#             */
/*   Updated: 2023/11/20 20:28:18 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != (unsigned char)c)
	{
		if (*(s + i) == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
/*#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello!";
	printf("%s", ft_strchr(str, 'l'));
}*/
