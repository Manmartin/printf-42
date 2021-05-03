/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:02:58 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:40:19 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	intlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int nb)
{
	int			size;
	int			sign;
	char		*str;
	long int	n;

	n = nb;
	sign = 1;
	size = intlen(n);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	str[--size] = '\0';
	if (n < 0)
		sign = -1;
	while (--size)
	{
		str[size] = (n * sign) % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	else
		str[0] = n % 10 + '0';
	return (str);
}
