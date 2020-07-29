/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:48:58 by sseo              #+#    #+#             */
/*   Updated: 2020/04/05 03:29:51 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		idx;
	size_t		len_diff;

	len_diff = ft_strlen(big);
	len_diff = len_diff > len ? len : len_diff;
	if (len_diff < ft_strlen(little))
		return (NULL);
	len_diff = len_diff - ft_strlen(little) + 1;
	while (len_diff)
	{
		idx = 0;
		while (little[idx])
		{
			if (*(big + idx) != little[idx])
				break ;
			idx++;
		}
		if (!(little[idx]))
			return ((char *)big);
		len_diff--;
		big++;
	}
	return (NULL);
}
