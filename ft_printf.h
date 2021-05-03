/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:01:45 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/03 15:08:22 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int		ljustify;
	int		zero;
	int		width;
	int		are_prc;
	int		precision;
}	t_flags;

void	flag_detector(const char **fmt, t_flags *flags, va_list *args);
int		put_chr(char id, va_list *args, t_flags *flags);

int		put_str(char id, va_list *args, t_flags *flags);
int		put_int(va_list *args, t_flags *flags);
int		put_uint(char id, va_list *args, t_flags *flags);

int		ft_printf(const char *ftm, ...);

void	ft_strupper(char **str, size_t len);
void	flag_init(t_flags *flags);
int		strset(char **str, int len, char c);
char	*hexa_ultoa(unsigned long int n, char c);
void	put_strwidth(char **str, t_flags *flags);

void	int_flags(char **str, t_flags *flags);
void	put_intwidth(char **str, t_flags *flags);
void	put_intprecision(char **str, t_flags *flags);
void	put_sign(int sign, char **str);

#endif