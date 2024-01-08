/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:40:29 by yu-chen           #+#    #+#             */
/*   Updated: 2023/12/04 21:32:46 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SPECIFIERS "cspdiuxX%%"
# define FLAGS "-+#0 "
# define OTHER ".*"

typedef struct s_struct
{
	va_list	ap;
	int		dash;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		star;
	size_t	width;
	int		dot;
	int		precision;
	char	*string;
	int		len;
	int		percent;
	char	specifier;
	int		is_pos;
	int		is_neg;
	int		is_nul;
	int		low_hex;
	int		upp_hex;
	int		is_str;
}	t_struct;

int		ft_printf(const char *s, ...);
void	init(t_struct *var);
void	set_flag(char c, t_struct *var);
void	parse_flags(const char **s, t_struct *var);
int		check_spec(t_struct *var);
int		put_str(char *s, t_struct *var);
int		put_int(int n, t_struct *var);
int		put_ptr(size_t ptr, t_struct *var);
int		put_unsign(unsigned int n, t_struct *var, char *base);
int		out_padding(t_struct *var, int add_wid, int add_prec);
int		count_padding(t_struct *var);

#endif
