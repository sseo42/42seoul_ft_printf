/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 17:27:11 by sseo              #+#    #+#             */
/*   Updated: 2020/06/07 16:11:16 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

__uint128_t	umul256(__uint128_t a, uint64_t bhi, uint64_t blow, __uint128_t *o)
{
	__uint128_t	matrix_128[4];
	uint64_t	matrix_64[4];
	uint64_t	matrix_64out[4];

	matrix_64[0] = (uint64_t)a;
	matrix_64[1] = (uint64_t)(a >> 64);
	matrix_128[0] = (__uint128_t)((uint64_t)a) * blow;
	matrix_128[1] = (__uint128_t)((uint64_t)a) * bhi;
	matrix_128[2] = (__uint128_t)((uint64_t)(a >> 64)) * blow;
	matrix_128[3] = (__uint128_t)((uint64_t)(a >> 64)) * bhi;
	matrix_64[2] = (uint64_t)matrix_128[0];
	matrix_64[3] = (uint64_t)(matrix_128[0] >> 64);
	matrix_128[2] += matrix_64[3];
	matrix_64out[0] = (uint64_t)matrix_128[2];
	matrix_64out[1] = (uint64_t)(matrix_128[2] >> 64);
	matrix_128[1] += matrix_64out[0];
	matrix_64out[2] = (uint64_t)matrix_128[1];
	matrix_64out[3] = (uint64_t)(matrix_128[1] >> 64);
	matrix_128[3] += matrix_64out[3] + matrix_64out[1];
	matrix_128[0] = (__uint128_t)matrix_64out[2] << 64 | matrix_64[2];
	*o = matrix_128[3];
	return (matrix_128[0]);
}

__uint128_t	umul256_hi(__uint128_t a, uint64_t bhi, uint64_t blow)
{
	__uint128_t	hi;

	umul256(a, bhi, blow, &hi);
	return (hi);
}

uint32_t	uint128_mod1e9(__uint128_t v)
{
	uint64_t	multiplied;
	uint32_t	shifted;

	multiplied = (uint64_t)umul256_hi(v, 0x89705F4136B4A597u, \
			0x31680A88F8953031u);
	shifted = (uint32_t)(multiplied >> 29);
	return ((uint32_t)v - 1000000000 * shifted);
}

uint32_t	mulshift_mod1e9(uint64_t m, const uint64_t mul[3], int32_t j)
{
	__uint128_t b0;
	__uint128_t mid;
	__uint128_t s1;

	b0 = (__uint128_t)m * mul[0];
	mid = (__uint128_t)m * mul[1] + (uint64_t)(b0 >> 64);
	s1 = (__uint128_t)m * mul[2] + (uint64_t)(mid >> 64);
	return (uint128_mod1e9(s1 >> (j - 128)));
}
