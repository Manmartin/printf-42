/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:00:51 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/05 12:45:34 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	put_strprecision(char **str, t_flags *flags)
{
	char	*aux;
	int		len;

	len = flags->precision;
	if (len == 0)
	{
		free(*str);
		*str = ft_strdup("");
	}
	else if (len < ft_strlen(*str))
	{
		aux = (char *)ft_calloc(len + 1, 1);
		ft_strlcpy(aux, (const char *)*str, len + 1);
		free(*str);
		*str = aux;
	}
}

static char	*pointer_maker(unsigned long int n, char c, t_flags *flags)
{
	char	*str;
	char	*aux;

	aux = hexa_ultoa(n, c);
	str = ft_strjoin("0x", aux);
	free(aux);
	put_strwidth(&str, flags);
	return (str);
}

static void	str_flags(char id, char **str, t_flags *flags)
{
	if (id == 's' && flags->are_prc)
		put_strprecision(str, flags);
	put_strwidth(str, flags);
}

int	put_str(char id, va_list *args, t_flags *flags)
{
	int		char_count;
	char	*str;

	if (id == 'p')
		str = pointer_maker(va_arg(*args, unsigned long int), id, flags);
	else
		str = va_arg(*args, char *);
	if (str == 0 && id == 's')
		str = ft_strdup("(null)");
	else if (id == 's')
		str = ft_strdup(str);
	str_flags(id, &str, flags);
	if (str)
	{
		char_count = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (char_count);
}
