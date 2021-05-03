/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:42:35 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 11:46:57 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*utoa_base(unsigned int n, int base)
{
	unsigned int	size;
	unsigned int	nb;
	char			*str;

	nb = n;
	size = 1;
	while (nb > base - 1)
	{
		nb /= base;
		size++;
	}
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	while (--size)
	{
		str[size] = n % base + '0';
		n /= base;
	}
	str[0] = n % base + '0';
	return (str);
}

int	put_uint(char id, va_list *args, t_flags *flags)
{
	char	*str;
	int		char_count;

	if (id == 'u')
		str = utoa_base(va_arg(*args, unsigned int), 10);
	else if (id == 'x' || id == 'X')
		str = hexa_ultoa(va_arg(*args, unsigned int), id);
	if (id != 'p')
		int_flags(&str, flags);
	if (str)
	{
		char_count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (char_count);
}
