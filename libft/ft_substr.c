/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:12:29 by sseo              #+#    #+#             */
/*   Updated: 2020/04/06 02:01:40 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*out;
	size_t		s_len;

	s_len = ft_strlen((const char *)s);
	if (start > s_len)
		len = 0;
	else
		len = len > s_len - (size_t)start ? s_len - (size_t)start : len;
	if ((out = (char *)malloc((len + 1) * sizeof(char))))
	{
		ft_memcpy((void *)out, (void *)(s + start), len * sizeof(char));
		out[len] = 0;
		return (out);
	}
	return (0);
}
