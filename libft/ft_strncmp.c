/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:47:43 by sseo              #+#    #+#             */
/*   Updated: 2020/03/01 00:04:26 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *src1, const char *src2, size_t n)
{
	if (n)
	{
		while (*src1 && *src2 && --n)
		{
			if (*src1 != *src2)
				break ;
			src1++;
			src2++;
		}
		return ((unsigned char)*src1 - (unsigned char)*src2);
	}
	return (0);
}
