/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:11:52 by sseo              #+#    #+#             */
/*   Updated: 2020/04/05 18:19:29 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_all(char **out, int out_idx)
{
	int			idx;

	idx = 0;
	while (idx < out_idx)
	{
		free(out[idx]);
		idx++;
	}
	free(out);
	return (0);
}

int		len_by_sep(const char *s, char c, int start)
{
	int			idx;

	idx = 0;
	while (s[start + idx] != 0)
	{
		if (s[start + idx] == c)
			return (idx);
		idx++;
	}
	return (idx);
}

int		get_size(const char *s, char c)
{
	int			cnt;
	int			idx;
	int			len;

	cnt = 0;
	idx = 0;
	while (s[idx] != 0)
	{
		len = len_by_sep(s, c, idx);
		if (len)
			cnt++;
		if (s[idx + len] != 0)
			idx++;
		idx += len;
	}
	return (cnt);
}

char	**make_out(const char *s, char c)
{
	char		**out;
	int			idx;
	int			out_idx;
	int			size;
	int			len;

	size = get_size(s, c);
	if (!(out = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	out_idx = 0;
	idx = 0;
	while (out_idx < size)
	{
		len = len_by_sep(s, c, idx);
		if (len)
		{
			if (!(out[out_idx] = (char *)malloc(len + 1)))
				return (ft_free_all(out, out_idx));
			out_idx++;
		}
		idx += 1 + len;
	}
	return (out);
}

char	**ft_split(const char *s, char c)
{
	char		**out;
	int			idx;
	int			out_idx;
	int			len;
	int			size;

	size = get_size(s, c);
	if (!(out = make_out(s, c)))
		return (0);
	out_idx = 0;
	idx = 0;
	while (out_idx < size)
	{
		len = len_by_sep(s, c, idx);
		if (len)
		{
			out[out_idx][len] = 0;
			while (--len >= 0)
				out[out_idx][len] = s[idx + len];
			out_idx++;
		}
		idx += 1 + len_by_sep(s, c, idx);
	}
	out[size] = 0;
	return (out);
}
