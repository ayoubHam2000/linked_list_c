/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:13:53 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/14 14:49:54 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include <stdio.h>

int	*p_int(int a)
{
	int	*p;

	p = malloc(sizeof(int));
	if (p)
		*p = a;
	return (p);
}

void	*clone_int(void *p)
{
	int	*new;

	if (p)
	{
		new = malloc(sizeof(int));
		*new = *((int *)p);
		return (new);
	}
	return (NULL);
}

int	main()
{
	t_list	*list;
	t_list	*clone_list;
	t_node	*node;

	list = l_init();
	l_append_end(list, p_int(1));
	l_append_end(list, p_int(22));
	l_append_end(list, p_int(3));
	l_append_end(list, p_int(4));
	printf("len = %ld\n", list->len);
	
	clone_list = l_clone(list, clone_int);

	node = clone_list->head;
	while (node)
	{
		printf("%d -> ", *((int *)(node->p)));
		node = node->next;
	}
	l_del_all(clone_list, NULL);
	free(clone_list);
	l_del_all(list, NULL);
	free(list);
	system("leaks linked_list");
	return (0);
}
