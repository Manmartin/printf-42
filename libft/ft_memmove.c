/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:05:38 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 10:57:29 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*aux_dest;
	void	*aux_src;

	aux_dest = dest + len - 1;
	aux_src = (void *)src + len - 1;
	if (!src && !dest)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			*(unsigned char *)aux_dest-- = *(unsigned char *)aux_src--;
	}
	return (dest);
}
