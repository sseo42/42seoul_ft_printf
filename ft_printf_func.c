/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:40:20 by sseo              #+#    #+#             */
/*   Updated: 2020/06/04 15:46:24 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_field_adder(int len, char c, char **str, int to_head)
{
	char			*adder;
	int				str_len;

	str_len = (int)ft_strlen((const char *)(*str));
	if (len > str_len)
	{
		if (!(adder = (char *)malloc((len + 1) * sizeof(char))))
		{
			ft_free((void **)str);
			return (0);
		}
		ft_memset((void *)adder, c, (size_t)len);
		if (to_head)
			ft_memcpy((void *)(adder + len - str_len), \
					(void *)(*str), (size_t)str_len);
		else
			ft_memcpy((void *)adder, (void *)(*str), (size_t)str_len);
		adder[len] = 0;
		ft_free((void **)str);
		return (adder);
	}
	return (*str);
}

int				ft_min_field_i(int64_t *info, char **str)
{
	int			len;
	int			dif;

	if (info[0] & 1 << 2 && info[2] < 0 && info[1] >= 0)
	{
		dif = (int)info[1] - (int)ft_strlen((const char *)(*str));
		if (!((*str) = ft_field_adder((int)info[1], '0', str, 1)))
			return (6);
		if (dif > 0)
			if ((*str)[dif] == '-' || (*str)[dif] == '+' || (*str)[dif] == ' ')
				ft_swap((*str), &(*str)[dif]);
	}
	else if (info[0] & 1 << 4)
		(*str) = ft_field_adder(abs((int)info[1]), ' ', str, 0);
	else
		(*str) = ft_field_adder((int)info[1], ' ', str, 1);
	if (!(*str))
		return (6);
	len = (int)ft_strlen((const char *)(*str));
	info[4] += (int64_t)len;
	write(1, *str, len);
	ft_free((void **)str);
	return (0);
}

char			*ft_unsigned_itoa_base(uint64_t num, const char *base)
{
	char			*out;
	uint64_t		size;
	uint64_t		m;
	uint64_t		base_len;

	m = num;
	size = num ? 0 : 1;
	base_len = (uint64_t)ft_strlen(base);
	while (m)
	{
		size++;
		m /= base_len;
	}
	if (!(out = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	out[size] = 0;
	while (size--)
	{
		out[size] = base[num - (num / base_len * base_len)];
		num /= base_len;
	}
	return (out);
}

int				head_double(int64_t *info, char **str)
{
	char			*temp;

	if (**str == '+')
	{
		if (info[0] & 1 << 1)
			**str = ' ';
		else if (!(info[0] & 1 << 3))
		{
			temp = *str;
			*str = ft_strdup((const char *)(*str + 1));
			ft_free((void **)(&temp));
		}
		if (!(*str))
			return (6);
	}
	info[2] = -1;
	return (ft_min_field_i(info, str));
}
