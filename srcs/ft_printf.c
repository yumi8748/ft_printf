/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:35:15 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/08 13:41:29 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **s, t_struct *var)
{
	init(var);
	while (ft_strchr(FLAGS, **s))
		set_flag(*(*s)++, var);
	if (**s == '*')
	{
		var->width = va_arg(var->ap, int);
		(*s)++;
	}
	else
		var->width = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	if (**s == '.')
	{
		var->dot = 1;
		if (*(++*s) == '*' && (*s)++)
			var->precision = va_arg(var->ap, int);
		else
			var->precision = ft_atoi(*s);
		if (var->precision < 0)
			var->precision = 1;
		while (ft_isdigit(**s))
			(*s)++;
	}
}

int	check_spec(t_struct *var)
{
	if (var->specifier == 's')
		return (put_str(va_arg(var->ap, char *), var));
	else if (var->specifier == 'p')
		return (put_ptr(va_arg(var->ap, size_t), var));
	else if (var->specifier == 'd' || var->specifier == 'i')
		return (put_int(va_arg(var->ap, int), var));
	else if (var->specifier == 'u')
		return (put_unsign(va_arg(var->ap, unsigned int), var, DEC));
	else if (var->specifier == 'x' && ++var->low_hex)
		return (put_unsign(va_arg(var->ap, unsigned int), var, LOW_HEX));
	else if (var->specifier == 'X' && ++var->upp_hex)
		return (put_unsign(va_arg(var->ap, unsigned int), var, UPP_HEX));
	else if (var->specifier == '%' && ++var->percent)
		var->string = ft_strdup("%");
	else if (var->specifier == 'c')
		var->string = ft_strdup((char []){va_arg(var->ap, int), 0});
	if (!var->string)
		return (-1);
	var->len = 1;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_struct	var;
	int			res;

	if (!s)
		return (-1);
	va_start(var.ap, s);
	res = 0;
	while (*s)
	{
		if (*s == '%' && ++s)
		{
			parse_flags(&s, &var);
			var.specifier = *s;
			if (check_spec(&var) == -1)
				return (-1);
			res += count_padding(&var);
			free(var.string);
		}
		else
			res += write(1, s, 1);
		s++;
	}
	va_end(var.ap);
	return (res);
}
