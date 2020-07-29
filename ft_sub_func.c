/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:13:48 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 21:35:08 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double			ft_int_plus_power(double num, uint32_t power)
{
	double			out;

	out = 1;
	while (power--)
		out *= num;
	return (out);
}

double			ft_int_natural_log(uint64_t num)
{
	double			out;
	double			val;
	uint32_t		cnt;

	out = 0;
	cnt = 1;
	val = ((double)num - 1) / ((double)num + 1);
	while (cnt < 1000)
	{
		out += ft_int_plus_power(val, cnt) / (double)cnt;
		cnt += 2;
	}
	return (out * 2);
}

double			ft_int_common_log(uint64_t num)
{
	double			out;

	out = ft_int_natural_log(num) / ft_int_natural_log(10);
	return (out);
}

int				ft_rev_step_func(int num)
{
	if (num > 0)
		return (0);
	return (num);
}

void			ft_put_uni(wchar_t uni)
{
	char			c;

	if (uni >= CHAR_MIN && uni <= CHAR_MAX)
	{
		c = (char)uni;
		write(1, &c, 1);
	}
	else
		write(1, &uni, sizeof(wchar_t));
}
