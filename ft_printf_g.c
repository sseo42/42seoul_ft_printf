/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 21:48:09 by sseo              #+#    #+#             */
/*   Updated: 2020/06/13 07:42:02 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char const	*e_zero(char const *str, int64_t expo)
{
	char			*e_point;
	char			*del_point;
	char			*out;

	if (!(expo & 1))
	{
		e_point = (char *)str;
		while (*e_point != 'e')
			e_point++;
		del_point = e_point;
		while (*(del_point - 1) == '0' && *(del_point - 2) != '-' \
				&& *(del_point - 2) != '+')
			del_point--;
		if (*(del_point - 1) == '.')
			del_point--;
		*del_point = 0;
		out = ft_strjoin(str, (char const *)e_point);
		ft_free(&str);
		if (!out)
			return (0);
		return ((char const *)out);
	}
	return (str);
}

char const	*ft_sub_g(t_double n, int64_t *expo, int32_t e[5])
{
	char const		*str;
	char			*z_p;

	if (!(str = ft_d2exp(n, expo, e)))
		return (0);
	if (e[3] > -5 && (e[3] < 0 || e[3] < e[4]))
	{
		expo[2] = (int64_t)(e[4] - e[3] - 1);
		ft_free(&str);
		if (!(str = ft_d2fixed(n, expo)))
			return (0);
		if (!(expo[0] & 1))
		{
			z_p = (char *)str;
			while (*z_p)
				z_p++;
			while (*(z_p - 1) == '0' && *(z_p - 2) != '-' && *(z_p - 2) != '+')
				z_p--;
			if (*(z_p - 1) == '.')
				z_p--;
			*z_p = 0;
		}
		return (str);
	}
	return (e_zero(str, expo[0]));
}

int			ft_printf_g(int64_t *info, double num)
{
	t_double		n;
	int32_t			e[5];
	char			*str;

	n.f = num;
	if (info[2] < 0)
		info[2] = 6;
	ft_bzero((void *)e, sizeof(int32_t) * 5);
	e[4] = info[2] ? (int32_t)info[2] : 1;
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
	else if (!(str = (char *)ft_sub_g(n, info, e)))
		return (6);
	return (head_double(info, &str));
}
