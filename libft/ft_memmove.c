/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:47:40 by sseo              #+#    #+#             */
/*   Updated: 2020/04/05 18:19:02 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	unsigned char		*b;
	size_t				idx;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	idx = 0;
	if (a < b)
		while (idx++ < n)
			*(a + idx - 1) = *(b + idx - 1);
	else if (b < a)
		while (idx++ < n)
			*(a + n - idx) = *(b + n - idx);
	return (dest);
}
