/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:07:20 by sseo              #+#    #+#             */
/*   Updated: 2020/03/03 08:15:36 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	unsigned int	len;
	char			*out;

	idx = 0;
	len = (unsigned int)ft_strlen((const char *)s);
	if (!(out = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	while (idx < len)
	{
		out[idx] = f(idx, s[idx]);
		idx++;
	}
	out[idx] = 0;
	return (out);
}
