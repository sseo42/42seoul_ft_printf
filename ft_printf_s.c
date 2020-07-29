/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:15:03 by sseo              #+#    #+#             */
/*   Updated: 2020/06/05 14:29:53 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_s(int64_t *info, char *s)
{
	char			*str;

	if (!s)
		s = "(null)";
	if (info[2] < 0)
		str = ft_strdup((const char *)s);
	else
		str = ft_substr((char const *)s, 0, (size_t)info[2]);
	if (!str)
		return (6);
	return (ft_min_field_i(info, &str));
}

int					ft_printf_percent(int64_t *info)
{
	char			*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (6);
	*str = '%';
	*(str + 1) = 0;
	info[2] = -1;
	return (ft_min_field_i(info, &str));
}
