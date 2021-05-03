/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:29:14 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 11:16:33 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (i < len && haystack[j])
	{
		if (haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j] && i + j <= len)
				return ((char *)&haystack[i]);
			continue ;
		}
		j = 0;
		i++;
	}
	return (0);
}
