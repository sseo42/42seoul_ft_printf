/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mantissa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 13:33:03 by sseo              #+#    #+#             */
/*   Updated: 2020/06/07 17:05:20 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_rounding(void **target, char *dot_idx)
{
	char		**temp;

	temp = (char **)target;
	if (temp)
		append_char(temp, '0');
	if (dot_idx)
	{
		*dot_idx = '0';
		*(dot_idx + 1) = '.';
	}
}

int		rounding_iter(char **round_idx, char **dot_idx, int round_up, char c)
{
	if (c == '.')
		*dot_idx = *round_idx;
	else if (c == '9')
	{
		**round_idx = '0';
		return (1);
	}
	else
	{
		if (round_up == 2 && c % 2 == 0)
			return (0);
		**round_idx = c + 1;
		return (0);
	}
	return (round_up);
}

void	r_part(char **t, char *r_idx, int r_up, void (*f)(void **, char *))
{
	char		*dot_idx;
	char		c;

	dot_idx = 0;
	while (1)
	{
		r_idx--;
		c = *r_idx;
		if (c == '-' || c == '+')
		{
			*(r_idx + 1) = '1';
			f((void **)t, dot_idx);
			break ;
		}
		if (!(r_up = rounding_iter(&r_idx, &dot_idx, r_up, c)))
			break ;
	}
}

int		last_section(char **target, int r_up, uint32_t digits, uint32_t num)
{
	if (num > 0)
		append_n_digits(target, digits, num);
	if (r_up != 0)
		r_part(target, *target, r_up, *f_rounding);
	return (1);
}

int		mantissa_iter(char **t, uint64_t m2, int32_t box[4], uint32_t ubox[4])
{
	uint32_t	maximum;
	uint32_t	last_digit;
	uint32_t	loc;
	int			r_up;
	int32_t		gap;

	gap = -box[3] - (int32_t)ubox[2] - 1;
	maximum = ubox[2] - box[1] * 9;
	last_digit = 0;
	loc = 0;
	if ((uint32_t)box[1] < ubox[0] - 1)
	{
		append_n_digits(t, ubox[3], 9);
		return (0);
	}
	while (loc++ < 9 - maximum)
	{
		last_digit = ubox[3] % 10;
		ubox[3] /= 10;
	}
	if (last_digit != 5)
		r_up = last_digit > 5 ? 1 : 0;
	else
		r_up = (gap <= 0 || (gap < 60 && !(m2 & ((1ull << gap) - 1)))) ? 2 : 1;
	return (last_section(t, r_up, ubox[3], maximum));
}
