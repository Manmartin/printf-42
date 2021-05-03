/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:08:31 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 11:05:39 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*pointer;

	i = 0;
	while (s1[i])
		i++;
	pointer = malloc(sizeof(char) * (i + 1));
	if (!pointer)
		return (0);
	i = 0;
	while (s1[i])
	{
		pointer[i] = s1[i];
		i++;
	}
	pointer[i] = s1[i];
	return (pointer);
}
