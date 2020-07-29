/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:11:10 by sseo              #+#    #+#             */
/*   Updated: 2020/04/05 04:20:34 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	where_is(char target, char const *src)
{
	int		idx;

	idx = 0;
	while (src[idx])
	{
		if (src[idx] == target)
			return (idx);
		idx++;
	}
	return (-1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		start_idx;
	size_t		end_idx;
	char		*out;

	if (!(*s1))
		return ((char *)s1);
	start_idx = 0;
	end_idx = ft_strlen((const char *)s1) - 1;
	while (where_is(s1[start_idx], set) >= 0)
		start_idx++;
	while (where_is(s1[end_idx], set) >= 0 && end_idx > start_idx)
		end_idx--;
	if ((out = (char *)malloc((end_idx - start_idx + 2) * sizeof(char))))
	{
		out[0] = s1[start_idx];
		out[end_idx - start_idx + 1] = 0;
		while (end_idx > start_idx)
		{
			out[end_idx - start_idx] = s1[end_idx];
			end_idx--;
		}
		return (out);
	}
	return (0);
}
