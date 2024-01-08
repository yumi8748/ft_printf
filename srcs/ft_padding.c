/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:48:25 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/04 20:50:05 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	out_padding(t_struct *var, int add_wid, int add_prec)
{
	int	res;

	res = 0;
	while (!var->dash && !var->zero && add_wid--)
		res += write(1, " ", 1);
	if (var->is_pos && var->plus)
		res += write(1, "+", 1);
	else if (var->is_pos && var->space)
		res += write(1, " ", 1);
	else if (var->is_neg)
		res += write(1, "-", 1);
	if (var->hash && var->low_hex && !var->is_nul)
		res += write(1, "0x", 2);
	else if (var->hash && var->upp_hex && !var->is_nul)
		res += write(1, "0X", 2);
	while (var->zero && add_wid--)
		res += write(1, "0", 1);
	while (add_prec--)
		res += write(1, "0", 1);
	res += write(1, var->string, var->len);
	while (var->dash && !var->zero && add_wid--)
		res += write(1, " ", 1);
	return (res);
}

int	count_padding(t_struct *var)
{
	int	add_prec;
	int	add_wid;

	if (var->is_str && var->dot)
		var->len = ft_min(var->precision, var->len);
	if (var->dot)
		var->zero = 0;
	add_prec = ft_max(0, var->precision - var->len);
	if (var->is_str)
		add_prec = 0;
	add_wid = var->width - var->len - add_prec;
	if (var->is_pos || var->is_neg)
		add_wid--;
	if (var->hash)
		add_wid -= 2;
	add_wid = ft_max(0, add_wid);
	return (out_padding(var, add_wid, add_prec));
}
