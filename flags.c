/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:08:27 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/30 11:17:52 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	whatwidth(const char **fmt, t_flags *flags, va_list *args)
{
	if (**fmt == '*')
	{
		flags->width = va_arg(*args, int);
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
	{
		flags->width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

static void	whatprecision(const char **fmt, t_flags *flags, va_list *args)
{
	if (**fmt == '.')
	{
		flags->are_prc = 1;
		(*fmt)++;
		if (**fmt == '*')
		{
			flags->precision = va_arg(*args, int);
			if (flags->precision < 0)
				flags->are_prc = 0;
			(*fmt)++;
		}
		else if (ft_isdigit(**fmt))
		{
			flags->precision = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
		else
			flags->precision = 0;
	}
}

void	flag_detector(const char **fmt, t_flags *flags, va_list *args)
{
	flag_init(flags);
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flags->ljustify = 1;
		else if (**fmt == '0')
			flags->zero = 1;
		(*fmt)++;
	}
	if (flags->ljustify == 1 && flags->zero == 1)
		flags->zero = 0;
	whatwidth(fmt, flags, args);
	whatprecision(fmt, flags, args);
}
