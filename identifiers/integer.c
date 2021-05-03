/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:48:53 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/30 15:56:07 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	put_int(va_list *args, t_flags *flags)
{
	char	*str;
	int		char_count;

	str = ft_itoa(va_arg(*args, int));
	int_flags(&str, flags);
	if (str)
	{
		char_count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	flag_init(flags);
	return (char_count);
}
