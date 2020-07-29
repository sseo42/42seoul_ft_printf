/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:15:49 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 21:35:28 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_p(int64_t *info, char *p)
{
	size_t		num;
	char		*str;
	char		*temp;

	num = (size_t)p;
	if (!(str = ft_unsigned_itoa_base(num, "0123456789abcdef")))
		return (6);
	if (!p && !info[2])
		if (!(str = ft_strdup("")))
			return (6);
	str = ft_field_adder((int)info[2], '0', &str, 1);
	temp = ft_strjoin((char const *)"0x", (char const *)str);
	ft_free(&str);
	if (!temp)
		return (6);
	return (ft_min_field_i(info, &temp));
}
