/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:05:30 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 12:42:34 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	put_chrwidth(t_flags *flags)
{
	char	c;
	char	*str;

	if (flags->width > 0)
	{
		if (flags->zero && !flags->ljustify)
			c = '0';
		else
			c = ' ';
		strset(&str, flags->width, c);
		ft_putstr_fd(str, 1);
		free(str);
		return (flags->width);
	}
	else
		return (1);
}

int	put_chr(char id, va_list *args, t_flags *flags)
{
	char	c;
	int		len;
	char	*aux;

	if (id == '%')
		c = '%';
	else
		c = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->ljustify = 1;
	}
	if (!flags->ljustify)
		len = put_chrwidth(flags);
	write(1, &c, 1);
	if (flags->ljustify)
		len = put_chrwidth(flags);
	return (len);
}
