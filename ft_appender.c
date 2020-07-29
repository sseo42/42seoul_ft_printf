/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appender.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 15:33:09 by sseo              #+#    #+#             */
/*   Updated: 2020/06/03 18:10:10 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	digits_num(uint32_t num)
{
	unsigned int	cnt;

	cnt = 0;
	while (num)
	{
		cnt += 1;
		num /= 10;
	}
	return (cnt);
}

void			append_n_digits(char **target, uint32_t digits, unsigned int n)
{
	unsigned int	k;

	k = n;
	if (k)
	{
		while (k--)
		{
			*(*target + k) = (digits % 10) + '0';
			digits /= 10;
		}
		*target += n;
	}
}

void			append_e_digits(char **target, uint32_t digits, unsigned int n)
{
	unsigned int	k;

	k = n;
	if (k)
	{
		while (--k)
		{
			*(*target + k + 1) = (digits % 10) + '0';
			digits /= 10;
		}
		**target = digits % 10 + '0';
		*(*target + 1) = '.';
		*target += n + 1;
	}
}

void			append_char(char **target, char c)
{
	**target = c;
	(*target)++;
}

void			append_n_char(char **target, char c, size_t n)
{
	while (n)
	{
		**target = c;
		(*target)++;
		n--;
	}
}
