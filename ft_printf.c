/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:09:06 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 21:39:06 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** eror_case	-1:	unexpected eror
** 				-2:	wrong arg_info
** 				-3:	not compatible flag
** 				-4:	not comaptible precision
** 				-5:	not compatible min field
** 				-6:	malloc_failed
** 				-7:	wrong arg input
** 				-8:	field overflow
** 				-9:	not compatible len field
*/

int64_t			ft_flag_part(const char **f)
{
	int64_t			flag_info;

	flag_info = 0;
	while (**f == '-' || **f == '+' || **f == '0' || \
			**f == ' ' || **f == '#')
	{
		if (**f == '-')
			flag_info = flag_info | (1 << 4);
		if (**f == '+')
			flag_info = flag_info | (1 << 3);
		if (**f == '0')
			flag_info = flag_info | (1 << 2);
		if (**f == ' ')
			flag_info = flag_info | (1 << 1);
		if (**f == '#')
			flag_info = flag_info | (1 << 0);
		(*f)++;
	}
	return (flag_info);
}

int64_t			ft_field_part(const char **f, va_list *ap)
{
	int64_t			field_size;

	field_size = 0;
	if (**f == '*')
	{
		(*f)++;
		return ((int64_t)va_arg(*ap, int));
	}
	while (**f <= '9' && **f >= '0')
	{
		field_size = field_size * 10 + **f - '0';
		(*f)++;
		if (field_size >= (INT_MAX - 32))
			return (INT_MAX);
	}
	return (field_size);
}

void			ft_read_identifiers(const char **f, va_list *ap, int64_t *info)
{
	(*f)++;
	info[0] = ft_flag_part(f);
	info[1] = ft_field_part(f, ap);
	if (**f == '.')
	{
		(*f)++;
		info[2] = ft_field_part(f, ap);
	}
	else
		info[2] = -1;
	info[3] = 0;
	if (**f == 'l' || **f == 'h')
	{
		info[3] = (**f == 'l') ? 1 << 0 : 1 << 2;
		(*f)++;
	}
	if (**f == 'l' || **f == 'h')
	{
		if ((**f == 'l' && info[3] == 1 << 0) || \
				(**f == 'h' && info[3] == 1 << 2))
			info[3] *= 2;
		else
			info[3] = 1 << 4;
		(*f)++;
	}
}

char			ft_arg_part(const char **f)
{
	char			out;

	out = **f;
	if (out != 'c' && out != 's' && out != 'p' && out != 'd' && out != 'i' && \
		out != 'u' && out != 'x' && out != 'X' && out != '%' && \
		out != 'n' && out != 'f' && out != 'g' && out != 'e')
		return (0);
	(*f)++;
	return (out);
}

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	int64_t			format_info[5];
	char			arg_info;
	int				eror_case;

	format_info[4] = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			ft_read_identifiers(&format, &ap, format_info);
			arg_info = ft_arg_part(&format);
			if ((eror_case = ft_printf_branch(format_info, arg_info, &ap)))
				return (-eror_case);
		}
		else
		{
			write(1, format, 1);
			format_info[4]++;
			format++;
		}
	}
	va_end(ap);
	return (format_info[4]);
}
