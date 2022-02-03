/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/01/28 18:53:32 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	*l_clone_pointer(void *p, void *(*clone_ptr)(void *p))
{
	if (clone_ptr)
		return (clone_ptr(p));
	return (p);
}

t_list	*l_clone(t_list *list, void *(*clone_ptr)(void *p))
{
	t_list	*new_list;
	t_list	*new_pointer;
	t_node	*node;

	new_list = l_init();
	node = list->head;
	while (node)
	{
		new_pointer = l_clone_pointer(node->p, clone_ptr);
		l_append_end(new_list, new_pointer);
		node = node->next;
	}
	new_list->len = list->len;
	return (new_list);
}
