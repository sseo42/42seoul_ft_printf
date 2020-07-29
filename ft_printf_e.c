/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:54:13 by sseo              #+#    #+#             */
/*   Updated: 2020/06/13 07:34:59 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint32_t	ft_case34_iter(char **t, uint32_t digits, int32_t e[5], int32_t s)
{
	if (e[1])
	{
		if (e[1] + 9 > e[4])
		{
			e[2] = 9;
			return (digits);
		}
		append_n_digits(t, digits, 9);
		e[1] += 9;
	}
	else if (digits)
	{
		e[2] = digits_num(digits);
		e[3] = s * 9 + e[2] - 1;
		if (e[2] > e[4])
			return (digits);
		if (e[4] > 1)
			append_e_digits(t, digits, (unsigned int)e[2]);
		else
			append_char(t, '0' + digits);
		e[1] = e[2];
		e[2] = 0;
	}
	return (1000000000);
}

uint32_t	ft_case3(char **target, uint64_t m2, int32_t e[5])
{
	uint32_t		idx;
	uint32_t		digits;
	uint32_t		j;
	int32_t			len;

	if (e[0] < -52)
		return (0);
	idx = e[0] < 0 ? 0 : (e[0] + 15) / 16;
	j = 16 * idx + 120 - e[0];
	len = ((int32_t)(16 * (double)idx * ft_int_common_log(2)) + 25) / 9;
	while (len-- > 0)
	{
		digits = mulshift_mod1e9(m2 << 8, \
				g_pow10_split[g_pow10_offset[idx] + len], (int32_t)j + 8);
		if (ft_case34_iter(target, digits, e, len) < 1000000000)
			return (digits);
	}
	return (digits);
}

uint32_t	ft_case4(char **target, uint64_t m2, int32_t e[5])
{
	int32_t			idx;
	int32_t			i;
	int32_t			j;
	uint32_t		p;
	uint32_t		digits;

	idx = -e[0] / 16;
	i = -1;
	j = 120 - e[0] - 16 * idx;
	while (++i < 200 - g_min_block[idx])
	{
		p = g_pow10_offset_2[idx] + i;
		digits = (p >= g_pow10_offset_2[idx + 1]) ? 0 : \
				mulshift_mod1e9(m2 << 8, g_pow10_split_2[p], j + 8);
		if (ft_case34_iter(target, digits, e, -(i + g_min_block[idx] + 1)) < \
				1000000000)
			return (digits);
	}
	return (digits);
}

char const	*ft_d2exp(t_double n, int64_t *expo, int32_t e[5])
{
	uint64_t		m2;
	uint32_t		digits;
	char const		*out;
	char			*out_p;

	decode_double(n, &m2, &e[0]);
	if (!(out = (char *)malloc(2000 * sizeof(char))))
		return (0);
	out_p = (char *)out;
	n.s_p.sign ? append_char(&out_p, '-') : append_char(&out_p, '+');
	digits = ft_case3(&out_p, m2, e);
	if (e[0] < 0 && e[2] == 0)
		digits = ft_case4(&out_p, m2, e);
	e_last(&out_p, m2, digits, e);
	if (e[4] < 2 && (expo[0] & 1))
		append_char(&out_p, '.');
	append_char(&out_p, 'e');
	e[3] < 0 ? append_char(&out_p, '-') : append_char(&out_p, '+');
	append_n_digits(&out_p, (uint32_t)ft_abs((int)e[3]), e[3] < 100 ? 2 : 3);
	*out_p = 0;
	return (out);
}

int			ft_printf_e(int64_t *info, double num)
{
	t_double			n;
	int32_t				e[5];
	char				*str;

	n.f = num;
	if (info[2] < 0)
		info[2] = 6;
	ft_bzero((void *)e, sizeof(int32_t) * 5);
	e[4] = (int32_t)info[2] + 1;
	if (n.s_p.exponent == 2047)
	{
		if (n.s_p.mantissa == 0)
		{
			if (!(str = ft_strdup("inf")))
				return (6);
		}
		else
		{
			if (!(str = ft_strdup("nan")))
				return (6);
		}
	}
	else if (!(str = (char *)ft_d2exp(n, info, e)))
		return (6);
	return (head_double(info, &str));
}
