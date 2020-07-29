/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:09:03 by sseo              #+#    #+#             */
/*   Updated: 2020/06/05 14:05:11 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_ox(int64_t *info, char **str, uint8_t is_large)
{
	char		*out;

	if (info[2] < 0 && info[0] & 1 << 2)
		*str = ft_field_adder((int)info[1] - 2, '0', str, 1);
	if (!(*str))
		return (0);
	if (is_large)
		out = ft_strjoin((char const *)"0X", (char const *)(*str));
	else
		out = ft_strjoin((char const *)"0x", (char const *)(*str));
	ft_free((void **)str);
	if (!out)
		return (0);
	return (out);
}

int				ft_printf_x(int64_t *info, uint64_t num, uint8_t is_large)
{
	char		*str;

	if (info[3] & 1 << 3)
		num = (uint64_t)((unsigned char)num);
	else if (info[3] & 1 << 2)
		num = (uint64_t)((unsigned short)num);
	else if (!info[3])
		num = (uint64_t)((unsigned int)num);
	else if (info[3] & 1 << 0)
		num = (uint64_t)((unsigned long)num);
	if (!info[2] && !num)
	{
		if (!(str = ft_strdup("")))
			return (6);
	}
	else if (!(str = is_large ? ft_unsigned_itoa_base(num, "0123456789ABCDEF") \
				: ft_unsigned_itoa_base(num, "0123456789abcdef")))
		return (6);
	if (!(str = ft_field_adder((int)info[2], '0', &str, 1)))
		return (6);
	if (info[0] & 1 && num)
		if (!(str = ft_ox(info, &str, is_large)))
			return (6);
	return (ft_min_field_i(info, &str));
}
