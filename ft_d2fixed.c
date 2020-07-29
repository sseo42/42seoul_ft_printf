/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d2fixed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:40:05 by sseo              #+#    #+#             */
/*   Updated: 2020/06/07 16:50:56 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decode_double(t_double n, uint64_t *m2, int32_t *e2)
{
	if (n.s_p.exponent)
	{
		*m2 = (1ull << 52) | n.s_p.mantissa;
		*e2 = (int32_t)n.s_p.exponent - 1023 - 52;
	}
	else
	{
		*m2 = n.s_p.mantissa;
		*e2 = 1 - 1023 - 52;
	}
}

int32_t	pow5_factor(uint64_t m2)
{
	uint64_t		temp;
	int32_t			cnt;

	cnt = 0;
	temp = m2 % 5;
	while (temp == 0)
	{
		cnt++;
		m2 /= 5;
		temp = m2 % 5;
	}
	return (cnt);
}

int		e_rounding_info(uint64_t m2, int32_t max, int32_t e[5], uint32_t *d)
{
	int32_t			rexp;
	uint32_t		last_d;
	int				round_up;

	rexp = e[4] - e[3];
	round_up = 0;
	last_d = 0;
	while (max++ < e[2])
	{
		last_d = *d % 10;
		*d /= 10;
	}
	if (last_d != 5)
		round_up = last_d > 5;
	else
	{
		round_up = (-e[0] - rexp <= 0 || (-e[0] - rexp < 60 && \
					!(m2 & ((1ull << (-e[0] - rexp)) - 1)))) ? 2 : 1;
		if (rexp < 0)
			round_up = ((round_up == 2) && pow5_factor(m2) >= -rexp) ? 2 : 1;
	}
	return (round_up);
}

void	e_last(char **target, uint64_t m2, uint32_t digits, int32_t e[5])
{
	int32_t		max;
	int			round_up;

	max = e[4] - e[1];
	round_up = e_rounding_info(m2, max, e, &digits);
	if (e[1] != 0)
	{
		if (digits == 0)
			append_n_char(target, '0', (size_t)max);
		else
			append_n_digits(target, digits, (unsigned int)max);
	}
	else
	{
		if (e[4] > 1)
			append_e_digits(target, digits, (unsigned int)max);
		else
			append_char(target, '0' + digits);
	}
	if (round_up != 0)
		r_part(target, *target, round_up, *e_rounding);
}

void	e_rounding(void **target, char *dot_idx)
{
	int32_t		**temp;

	temp = (int32_t **)target;
	(**temp)++;
	*dot_idx = 0;
}
