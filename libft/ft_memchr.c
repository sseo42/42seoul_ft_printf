/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:30:42 by sseo              #+#    #+#             */
/*   Updated: 2020/02/29 23:36:16 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	cmp;

	s = (unsigned char *)src;
	cmp = (unsigned char)c;
	while (n)
	{
		if (*s == cmp)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}
