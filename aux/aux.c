/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 13:07:40 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 11:47:38 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_strupper(char **str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[0][i] = ft_toupper(str[0][i]);
		i++;
	}	
}

void	flag_init(t_flags *flags)
{
	flags->ljustify = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->are_prc = 0;
	flags->precision = 0;
}

int	strset(char **str, int len, char c)
{
	*str = (char *)ft_calloc(len, 1);
	if (!*str)
		return (0);
	len--;
	while (len)
		(*str)[--len] = c;
	return (1);
}

char	*hexa_ultoa(unsigned long int n, char c)
{
	unsigned long int	size;
	unsigned long int	nb;
	char				*str;
	char				*base;

	base = "0123456789abcdef";
	nb = n;
	size = 1;
	while (nb > 15)
	{
		nb /= 16;
		size++;
	}
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (0);
	while (--size)
	{
		str[size] = base[n % 16];
		n /= 16;
	}
	str[0] = base[n % 16];
	if (c == 'X')
		ft_strupper(&str, ft_strlen(str));
	return (str);
}

void	put_strwidth(char **str, t_flags *flags)
{	
	char	*aux;
	char	*s1;
	int		width_len;

	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->ljustify = 1;
	}
	width_len = flags->width - ft_strlen(*str);
	if (width_len < 0)
		width_len = 0;
	strset(&aux, width_len + 1, ' ');
	s1 = *str;
	if (flags->ljustify == 0)
		*str = ft_strjoin(aux, s1);
	else
		*str = ft_strjoin(s1, aux);
	free(s1);
	free(aux);
}
