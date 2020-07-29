/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:14:27 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 20:24:37 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_u(int64_t *info, uint64_t num)
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
	else if (!(str = ft_unsigned_itoa_base(num, "0123456789")))
		return (6);
	if (!(str = ft_field_adder((int)info[2], '0', &str, 1)))
		return (6);
	return (ft_min_field_i(info, &str));
}
