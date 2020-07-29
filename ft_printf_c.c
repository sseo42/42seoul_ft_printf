/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:31:31 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 21:33:02 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_c_to_s(int64_t *info, wint_t c)
{
	char		str[2];
	wchar_t		uni[2];

	if (!info[3])
	{
		str[0] = (char)c;
		str[1] = 0;
		return (ft_printf_s(info, str));
	}
	uni[0] = c;
	uni[1] = 0;
	return (ft_printf_ws(info, uni));
}

int				ft_printf_c(int64_t *info, wint_t c)
{
	int			eror_case;

	if (!c)
	{
		info[4]++;
		if (info[1] > 0)
			info[1]--;
		if (info[1] < 0)
			info[1]++;
		if (info[0] & 1 << 4)
			write(1, "\x00", 1);
	}
	info[2] = c ? 1 : 0;
	eror_case = ft_c_to_s(info, c);
	if (!c)
		if (!info[0])
			write(1, "\x00", 1);
	return (eror_case);
}
