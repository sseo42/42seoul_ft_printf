/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:04:40 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 20:57:03 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_i_sub(int64_t *info, char **str, int64_t num)
{
	char		*temp;

	temp = *str;
	if (num < 0)
	{
		*str = ft_strjoin((char const *)"-", (char const *)(*str));
		ft_free((void **)(&temp));
	}
	else if (info[0] & 10)
	{
		if (info[0] & 1 << 1)
			*str = ft_strjoin((char const *)" ", (char const *)(*str));
		else
			*str = ft_strjoin((char const *)"+", (char const *)(*str));
		ft_free((void **)(&temp));
	}
	if (!(*str))
		return (6);
	return (ft_min_field_i(info, str));
}

int			ft_printf_i(int64_t *info, int64_t num)
{
	char		*str;
	char		*base;

	base = "0123456789";
	if (info[3] & 1 << 2)
		num = (int64_t)((short int)num);
	else if (info[3] & 1 << 3)
		num = (int64_t)((char)num);
	else if (!info[3])
		num = (int64_t)((int)num);
	else if (info[3] & 1 << 0)
		num = (int64_t)((long)num);
	if (!info[2] && !num)
	{
		if (!(str = ft_strdup("")))
			return (6);
	}
	else if (!(str = (num < 0) ? ft_unsigned_itoa_base((uint64_t)(-num), \
					base) : ft_unsigned_itoa_base((uint64_t)num, base)))
		return (6);
	if (!(str = ft_field_adder(info[2], '0', &str, 1)))
		return (6);
	return (ft_i_sub(info, &str, num));
}
