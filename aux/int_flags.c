/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:29:06 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 13:44:07 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_sign(int sign, char **str)
{
	char	*aux;

	if (sign && *str)
	{
		aux = *str;
		*str = ft_strjoin("-", *str);
		free(aux);
	}
}

static int	width_cnumber(char *chr, t_flags *flags, char **str)
{
	int	width_len;

	if (flags->zero && !flags->ljustify && flags->width > 0)
		*chr = '0';
	else
		*chr = ' ';
	width_len = flags->width - ft_strlen(*str);
	if (width_len < 0)
		width_len = 0;
	return (width_len);
}

void	put_intwidth(char **str, t_flags *flags)
{
	char	*aux;
	char	*s1;
	char	chr;
	int		width_len;
	int		sign;

	sign = 0;
	if (**str == '-')
		sign = 1;
	width_len = width_cnumber(&chr, flags, str);
	if (width_len > 0 && chr == ' ')
		put_sign(sign, str);
	strset(&aux, width_len + 1, chr);
	s1 = *str;
	if (flags->ljustify == 0)
		*str = ft_strjoin(aux, s1 + sign);
	else
		*str = ft_strjoin(s1 + sign, aux);
	free(s1);
	free(aux);
	if (!(width_len > 0 && chr == ' '))
		put_sign(sign, str);
}

void	put_intprecision(char **str, t_flags *flags)
{
	int		sign;
	int		len;
	char	*aux;
	char	*s1;

	sign = 0;
	if (**str == '-')
		sign = 1;
	if (**str == '0' && flags->precision == 0)
	{
		free(*str);
		*str = ft_calloc(1, 1);
	}
	len = flags->precision - ft_strlen(*str) + sign;
	if (len < 0)
		len = 0;
	strset(&aux, len + 1, '0');
	s1 = *str;
	*str = ft_strjoin(aux, *str + sign);
	free(s1);
	free(aux);
	put_sign(sign, str);
}

void	int_flags(char **str, t_flags *flags)
{
	if (flags->are_prc == 1)
	{
		put_intprecision(str, flags);
		put_strwidth(str, flags);
	}
	else
	{
		printf("");
		put_intwidth(str, flags);
	}
}
