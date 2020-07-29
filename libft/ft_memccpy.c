/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:17:55 by sseo              #+#    #+#             */
/*   Updated: 2020/02/29 21:56:38 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	cmp;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	cmp = (unsigned char)c;
	while (n)
	{
		*a = *b;
		if (*b == cmp)
			break ;
		b++;
		a++;
		n--;
	}
	a++;
	if (n)
		return ((void *)a);
	return (NULL);
}
