/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:49:11 by sseo              #+#    #+#             */
/*   Updated: 2020/03/04 18:26:50 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*out;
	t_list		*temp;

	out = 0;
	if (lst)
	{
		if (!(out = ft_lstnew(f(lst->content))))
			return (0);
		temp = out;
		lst = lst->next;
		while (lst)
		{
			if (!(temp->next = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&out, del);
				return (0);
			}
			temp = temp->next;
			lst = lst->next;
		}
		return (out);
	}
	return (0);
}
