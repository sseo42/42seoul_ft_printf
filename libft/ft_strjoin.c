/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:48:54 by sseo              #+#    #+#             */
/*   Updated: 2020/03/01 01:23:28 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*out;
	size_t		s1_len;
	size_t		s2_len;

	s1_len = ft_strlen((const char *)s1);
	s2_len = ft_strlen((const char *)s2);
	if ((out = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
	{
		ft_memcpy((void *)out, (void *)s1, s1_len * sizeof(char));
		ft_memcpy((void *)(out + s1_len), (void *)s2, s2_len * sizeof(char));
		out[s1_len + s2_len] = 0;
		return (out);
	}
	return (0);
}
