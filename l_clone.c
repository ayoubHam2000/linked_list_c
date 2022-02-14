/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_clone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:40:27 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 14:46:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static void	*l_clone_pointer(void *p, void *(*clone_ptr)(void *p))
{
	if (clone_ptr)
		return (clone_ptr(p));
	return (p);
}

//l_append_end can failed if malloc failed to create new node
//than new_list will be less than the original list 
t_list	*l_clone(t_list *list, void *(*clone_ptr)(void *p))
{
	t_list	*new_list;
	t_list	*new_pointer;
	t_node	*node;

	new_list = l_init();
	if (!new_list)
		return (NULL);
	node = list->head;
	while (node)
	{
		if (l_append_end(new_list, NULL))
		{
			new_pointer = l_clone_pointer(node->p, clone_ptr);
			new_list->last->p = new_pointer;
		}
		node = node->next;
	}
	return (new_list);
}
