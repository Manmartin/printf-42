/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:18:58 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:57:39 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *mem, int c, size_t n)
{
	void	*str;

	str = mem;
	while (n--)
	{
		*(unsigned char *)mem++ = (unsigned char)c;
	}
	return (str);
}
