/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:49:27 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 11:06:40 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size_str;

	if (!s1 || !s2)
		return (0);
	size_str = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(sizeof(char) * (size_str));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s1, size_str);
	ft_strlcat(new_str, s2, size_str);
	return (new_str);
}
