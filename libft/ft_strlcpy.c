/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:16:49 by sseo              #+#    #+#             */
/*   Updated: 2020/02/29 22:02:09 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t		src_size;
	size_t		len;

	src_size = ft_strlen(src);
	if (n)
	{
		len = (src_size < n) ? src_size : n - 1;
		ft_memcpy((void *)dest, (void *)src, len);
		dest[len] = 0;
	}
	return (src_size);
}
