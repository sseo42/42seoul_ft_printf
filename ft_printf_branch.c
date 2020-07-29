/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:48:47 by sseo              #+#    #+#             */
/*   Updated: 2020/06/05 14:25:06 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_signed_arg(int64_t *info, char arg, va_list *ap)
{
	int		eror_case;

	if (arg == 'i' || arg == 'd')
	{
		if (info[0] & 1)
			eror_case = 3;
		else if (info[3] & 1)
			eror_case = ft_printf_i(info, va_arg(*ap, long));
		else if (info[3] & 2)
			eror_case = ft_printf_i(info, va_arg(*ap, long long));
		else
			eror_case = ft_printf_i(info, va_arg(*ap, int));
	}
	else if (info[3] & 14)
		eror_case = 9;
	else if (arg == 'f')
		eror_case = ft_printf_f(info, va_arg(*ap, double));
	else if (arg == 'e')
		eror_case = ft_printf_e(info, va_arg(*ap, double));
	else if (arg == 'g')
		eror_case = ft_printf_g(info, va_arg(*ap, double));
	else
		eror_case = 1;
	return (eror_case);
}

int			ft_unsigned_arg(int64_t *info, const char ag, va_list *ap)
{
	if (info[0] & 10)
		return (3);
	else if (ag == 'x' || ag == 'X')
	{
		if (info[3] & 1)
			return (ft_printf_x(info, va_arg(*ap, unsigned long), \
						(ag == 'X')));
		else if (info[3] & 2)
			return (ft_printf_x(info, va_arg(*ap, unsigned long long), \
						(ag == 'X')));
		else
			return (ft_printf_x(info, va_arg(*ap, unsigned int), (ag == 'X')));
	}
	else if (info[0] & 1)
		return (3);
	else if (ag == 'u')
	{
		if (info[3] & 1)
			return (ft_printf_u(info, va_arg(*ap, unsigned long)));
		else if (info[3] & 2)
			return (ft_printf_u(info, va_arg(*ap, unsigned long long)));
		else
			return (ft_printf_u(info, va_arg(*ap, unsigned int)));
	}
	return (1);
}

int			ft_str_arg(int64_t *info, const char arg, va_list *ap)
{
	int		eror_case;

	if (info[0] & 15)
		eror_case = 3;
	else if (info[3] & 14)
		eror_case = 9;
	else if (arg == 's' && info[3])
		eror_case = ft_printf_ws(info, va_arg(*ap, wchar_t *));
	else if (arg == 's')
		eror_case = ft_printf_s(info, va_arg(*ap, char *));
	else if (arg == 'p')
		eror_case = ft_printf_p(info, va_arg(*ap, char *));
	else if (info[2] > 0)
		eror_case = 4;
	else if (arg == 'c')
		eror_case = ft_printf_c(info, (wint_t)va_arg(*ap, int));
	else
		eror_case = 1;
	return (eror_case);
}

int			ft_n_arg(int64_t *info, va_list *ap)
{
	void	*store;

	store = va_arg(*ap, void *);
	if (!store)
		return (2);
	else if (info[3] & 1 << 3)
		*((signed char *)store) = (signed char)info[4];
	else if (info[3] & 1 << 2)
		*((short int *)store) = (short int)info[4];
	else if (info[3] & 1 << 1)
		*((long int *)store) = (long int)info[4];
	else if (info[3] & 1 << 0)
		*((long long int *)store) = (long long int)info[4];
	else
		*((int *)store) = (int)info[4];
	return (0);
}

int			ft_printf_branch(int64_t *info, const char arg, va_list *ap)
{
	if (info[1] >= INT_MAX - 32 || info[2] >= INT_MAX - 32)
		return (8);
	if (info[1] < 0)
		info[0] = info[0] | 1 << 4;
	if (info[0] & 1 << 4 && info[0] & 1 << 2)
		info[0] -= 1 << 2;
	if (info[0] & 1 << 3 && info[0] & 1 << 1)
		info[0] -= 1 << 1;
	if (arg == '%')
		return (ft_printf_percent(info));
	if (info[3] & 1 << 4)
		return (9);
	if (arg == 'd' || arg == 'i' || arg == 'f' || arg == 'g' || arg == 'e')
		return (ft_signed_arg(info, arg, ap));
	else if (arg == 'u' || arg == 'x' || arg == 'X')
		return (ft_unsigned_arg(info, arg, ap));
	else if (arg == 'c' || arg == 's' || arg == 'p')
		return (ft_str_arg(info, arg, ap));
	else if (arg == 'n')
		return (ft_n_arg(info, ap));
	else
		return (2);
}
