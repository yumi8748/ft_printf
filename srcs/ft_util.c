/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:23:17 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/04 21:34:19 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_struct *var)
{
	var->dash = 0;
	var->plus = 0;
	var->hash = 0;
	var->zero = 0;
	var->space = 0;
	var->star = 0;
	var->width = 0;
	var->dot = 0;
	var->precision = 0;
	var->percent = 0;
	var->is_pos = 0;
	var->is_neg = 0;
	var->is_nul = 0;
	var->low_hex = 0;
	var->upp_hex = 0;
	var->is_str = 0;
	var->string = NULL;
}

void	set_flag(char c, t_struct *var)
{
	if (c == '-')
		var->dash = 1;
	else if (c == '+')
		var->plus = 1;
	else if (c == '#')
		var->hash = 1;
	else if (c == '0')
		var->zero = 1;
	else if (c == ' ')
		var->space = 1;
	else if (c == '.')
		var->dot = 1;
}
