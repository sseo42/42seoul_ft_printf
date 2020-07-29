/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:26:47 by sseo              #+#    #+#             */
/*   Updated: 2020/03/03 08:07:10 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void		ft_put_i(char *str, int n, int cnt)
{
	if (n)
	{
		str[cnt] = n % 10 + '0';
		ft_put_i(str, n / 10, cnt - 1);
	}
}

char			*ft_itoa(int n)
{
	int			m;
	char		*out;
	size_t		cnt;

	m = n;
	cnt = (m > 0) ? 0 : 1;
	while (m)
	{
		cnt++;
		m /= 10;
	}
	if (!(out = (char *)malloc(cnt + 1)))
		return (0);
	if (n < 0)
		out[0] = '-';
	ft_put_i(out, ft_abs(n / 10), cnt - 2);
	out[cnt - 1] = ft_abs(n % 10) + '0';
	out[cnt] = 0;
	return (out);
}
