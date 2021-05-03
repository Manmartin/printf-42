/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:51:08 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/27 11:03:58 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			s[j++] = 0;
		if (s[j] != c && s[j])
			i++;
		while (s[j] != c && s[j])
			j++;
	}
	return (i);
}

static int	ft_creator(char **buff, char *aux, int j, int i)
{
	while (j < i - 1)
	{
		while (!*aux)
			aux++;
		buff[j] = malloc(sizeof(char) * (ft_strlen(aux) + 1));
		if (!buff[j])
			return (0);
		ft_strlcpy(buff[j++], aux, ft_strlen(aux) + 1);
		while (*aux)
			aux++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**buff;
	char	*aux;
	char	*aux_aux;
	int		i;
	int		j;

	if (!s)
		return (0);
	j = 1 + ft_strlen(s);
	aux = malloc(sizeof(char) * j);
	if (!aux)
		return (0);
	aux_aux = aux;
	ft_strlcpy(aux, s, j);
	i = ft_wordcount(aux, c) + 1;
	j = 0;
	buff = (char **)malloc(sizeof(char *) * i);
	if (!buff)
		return (0);
	if (!ft_creator(buff, aux, j, i))
		return (0);
	buff[i - 1] = 0;
	free(aux_aux);
	return (buff);
}
