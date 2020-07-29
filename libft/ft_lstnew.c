/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:57:25 by sseo              #+#    #+#             */
/*   Updated: 2020/03/04 16:14:53 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*out;

	if (!(out = (t_list *)malloc(sizeof(t_list))))
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}
