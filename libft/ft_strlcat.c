/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:53:52 by sseo              #+#    #+#             */
/*   Updated: 2020/04/06 22:45:45 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		idx;
	size_t		src_idx;
	size_t		src_len;
	size_t		len;

	src_idx = 0;
	idx = 0;
	while (*(dst + idx) && idx < size)
		idx++;
	src_len = ft_strlen(src);
	len = src_len + idx;
	while (src_idx < src_len && src_idx + idx + 1 < size)
	{
		dst[idx + src_idx] = src[src_idx];
		src_idx++;
	}
	if (idx != size)
		dst[idx + src_idx] = 0;
	return (len);
}
