/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:39:49 by sseo              #+#    #+#             */
/*   Updated: 2020/03/24 19:03:00 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char		*out;
	size_t		n;

	n = ft_strlen(src);
	if ((out = (char *)malloc((n + 1) * sizeof(char))))
	{
		ft_memcpy((void *)out, (void *)src, n);
		out[n] = 0;
	}
	return (out);
}
