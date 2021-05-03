/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:07:52 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 11:07:12 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	write_point;
	size_t	i;

	i = 0;
	if (dst_size <= ft_strlen(dst))
		return (dst_size + ft_strlen(src));
	write_point = ft_strlen(dst);
	while (src[i] && write_point + 1 != dst_size)
		dst[write_point++] = src[i++];
	dst[write_point] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
