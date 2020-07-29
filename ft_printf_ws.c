/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:27:26 by sseo              #+#    #+#             */
/*   Updated: 2020/04/08 20:50:19 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t			*ft_subuni(wchar_t *s, int64_t max_width)
{
	wchar_t		*out;
	int64_t		s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (max_width >= s_len || max_width < 0)
	{
		out = (wchar_t *)malloc((s_len + 1) * sizeof(wchar_t));
		max_width = s_len;
	}
	else
		out = (wchar_t *)malloc((max_width + 1) * sizeof(wchar_t));
	if (!(out))
		return (0);
	s_len = 0;
	while (s_len < max_width)
	{
		out[s_len] = s[s_len];
		s_len++;
	}
	out[s_len] = 0;
	return (out);
}

wchar_t			*ft_uni_field_add(int len, wchar_t c, wchar_t **uni, int head)
{
	wchar_t		*out;
	int			uni_idx;
	int			out_idx;

	uni_idx = 0;
	out_idx = -1;
	while ((*uni)[uni_idx])
		uni_idx++;
	if (len <= uni_idx)
		return (*uni);
	if (!(out = (wchar_t *)malloc((len + 1) * sizeof(wchar_t))))
	{
		ft_free((void **)uni);
		return (0);
	}
	while (++out_idx < len)
		out[out_idx] = c;
	if (head)
		ft_memcpy((void *)(out + len - uni_idx), (void *)(*uni), \
				(size_t)uni_idx);
	else
		ft_memcpy((void *)out, (void *)(*uni), (size_t)uni_idx);
	out[len] = 0;
	ft_free((void **)uni);
	return (out);
}

int				ft_printf_ws(int64_t *info, wchar_t *s)
{
	wchar_t		*uni;
	int			s_len;

	s_len = 0;
	if (!s)
		s = L"(null)";
	if (!(uni = ft_subuni(s, info[2])))
		return (6);
	if (info[0] & 1 << 4)
		uni = ft_uni_field_add((int)info[1], ' ', &uni, 0);
	else
		uni = ft_uni_field_add((int)info[1], ' ', &uni, 1);
	if (!uni)
		return (6);
	s_len = 0;
	while (uni[s_len])
	{
		ft_put_uni(uni[s_len]);
		s_len++;
	}
	ft_free(&uni);
	info[4] += (int64_t)s_len;
	return (0);
}
