/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:06:08 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/04 20:35:42 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *s, t_struct *var)
{
	var->is_str = 1;
	if (!s)
	{
		if (var->dot && var->precision < (int)ft_strlen("(null)"))
			var->string = ft_strdup("");
		else
			var->string = ft_strdup("(null)");
	}
	else
		var->string = ft_strdup(s);
	if (!var->string)
		return (-1);
	var->len = ft_strlen(var->string);
	return (0);
}

int	put_int(int n, t_struct *var)
{
	if (n < 0)
	{
		var->is_neg = 1;
		n = (unsigned int)(-n);
	}
	else if (var->space || var->plus)
		var->is_pos = 1;
	var->string = ft_itoa_base((unsigned int)n, DEC);
	if (!var->string)
		return (-1);
	var->len = ft_strlen(var->string);
	if (!var->dot)
		var->precision = 1;
	if (!n && var->precision == 0)
		var->len = 0;
	return (0);
}	

int	put_ptr(size_t ptr, t_struct *var)
{
	if (!ptr)
	{
		var->string = ft_strdup("(nil)");
	}
	else
	{
		var->hash = 1;
		var->string = ft_itoa_base(ptr, LOW_HEX);
		var->low_hex = 1;
	}
	if (!var->string)
		return (-1);
	var->len = ft_strlen(var->string);
	return (0);
}

int	put_unsign(unsigned int n, t_struct *var, char *base)
{
	var->string = ft_itoa_base(n, base);
	if (!var->string)
		return (-1);
	var->len = ft_strlen(var->string);
	if (!var->dot)
		var->precision = 1;
	if (n == 0)
	{
		var->is_nul = 1;
		if (var->precision == 0)
			var->len = 0;
	}
	return (0);
}
