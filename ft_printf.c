/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:29:08 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 15:08:42 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_dt(const char **fmt, va_list *args, int *char_count, t_flags *flags)
{
	if (fmt[0][0] == '%')
	{
		(*fmt)++;
		flag_detector(fmt, flags, args);
		if (**fmt == 'c' || **fmt == '%')
			*char_count += put_chr(**fmt, args, flags);
		else if (**fmt == 's' || **fmt == 'p')
			*char_count += put_str(**fmt, args, flags);
		else if (**fmt == 'u' || **fmt == 'x' || **fmt == 'X')
			*char_count += put_uint(**fmt, args, flags);
		else if (**fmt == 'd' || **fmt == 'i')
			*char_count += put_int(args, flags);
	}
	else
		*char_count += write(1, *fmt, 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_flags	flags;
	int		char_count;

	va_start(args, fmt);
	char_count = 0;
	while (fmt[0])
	{
		arg_dt(&fmt, &args, &char_count, &flags);
		fmt++;
	}
	va_end(args);
	return (char_count);
}
