/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:26:42 by sseo              #+#    #+#             */
/*   Updated: 2020/03/04 17:46:14 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*current;
	t_list		*after;

	current = *lst;
	after = *lst;
	while (after)
	{
		after = after->next;
		del(current->content);
		free(current);
		current = after;
	}
	*lst = 0;
}
