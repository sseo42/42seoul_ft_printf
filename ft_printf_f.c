/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:11:52 by sseo              #+#    #+#             */
/*   Updated: 2020/06/13 07:26:55 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		zero_section(char **target, int32_t box[4], uint32_t ubox[4])
{
	if (ubox[0] <= g_min_block[box[0]])
	{
		append_n_char(target, '0', (size_t)ubox[2]);
		box[1] = (int32_t)ubox[0] - 1;
	}
	else if (box[1] + 1 < g_min_block[box[0]])
	{
		append_n_char(target, '0', (size_t)g_min_block[box[0]] * 9);
		box[1] = (int32_t)g_min_block[box[0]] - 1;
	}
}

int			ft_case1(char **target, uint64_t m2, int32_t e2)
{
	uint32_t		idx;
	uint32_t		digits;
	uint32_t		j;
	int32_t			len;
	int				flag;

	if (e2 < -52)
		return (0);
	idx = e2 < 0 ? 0 : (e2 + 15) / 16;
	j = 16 * idx + 120 - e2;
	len = ((int32_t)(16 * (double)idx * ft_int_common_log(2)) + 25) / 9;
	flag = 0;
	while (len-- > 0)
	{
		digits = mulshift_mod1e9(m2 << 8, \
				g_pow10_split[g_pow10_offset[idx] + len], (int32_t)j + 8);
		if (flag)
			append_n_digits(target, digits, 9);
		else if (digits)
		{
			append_n_digits(target, digits, digits_num(digits));
			flag = 1;
		}
	}
	return (flag);
}

void		ft_case2(char **target, uint64_t m2, int32_t e2, uint32_t precision)
{
	int32_t			collection_int[4];
	uint32_t		collection_uint[4];

	collection_int[0] = -e2 / 16;
	collection_int[1] = -1;
	collection_int[3] = e2;
	collection_uint[0] = precision / 9 + 1;
	collection_uint[2] = precision;
	zero_section(target, collection_int, collection_uint);
	while (++collection_int[1] < (int32_t)collection_uint[0])
	{
		collection_int[2] = 120 - e2 - 16 * collection_int[0];
		collection_uint[1] = g_pow10_offset_2[collection_int[0]] + \
							collection_int[1] - g_min_block[collection_int[0]];
		if (collection_uint[1] >= g_pow10_offset_2[collection_int[0] + 1])
		{
			append_n_char(target, '0', \
					(size_t)(precision - 9 * collection_int[1]));
			break ;
		}
		collection_uint[3] = mulshift_mod1e9(m2 << 8, \
				g_pow10_split_2[collection_uint[1]], collection_int[2] + 8);
		if (mantissa_iter(target, m2, collection_int, collection_uint))
			break ;
	}
}

char const	*ft_d2fixed(t_double n, int64_t *expo)
{
	uint64_t		m2;
	int32_t			e2;
	char const		*out;
	char			*out_p;

	decode_double(n, &m2, &e2);
	if (!(out = (char *)malloc(2000 * sizeof(char))))
		return (0);
	out_p = (char *)out;
	if (n.s_p.sign)
		append_char(&out_p, '-');
	else
		append_char(&out_p, '+');
	if (ft_case1(&out_p, m2, e2) == 0)
		append_char(&out_p, '0');
	if (expo[2] > 0 || (expo[0] & 1))
		append_char(&out_p, '.');
	if (e2 < 0)
		ft_case2(&out_p, m2, e2, (uint32_t)expo[2]);
	else
		append_n_char(&out_p, '0', (size_t)expo[2]);
	*out_p = 0;
	return (out);
}

int			ft_printf_f(int64_t *info, double num)
{
	t_double			n;
	char				*str;

	n.f = num;
	if (info[2] < 0)
		info[2] = 6;
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
	else if (!(str = (char *)ft_d2fixed(n, info)))
		return (6);
	return (head_double(info, &str));
}
