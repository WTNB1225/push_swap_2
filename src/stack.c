/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 07:10:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/26 01:51:27 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*head_node(void)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->next = head;
	head->prev = head;
	head->index = 0;
	head->value = 0;
	return (head);
}

void	add_tail(t_stack *head, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	tmp = head;
	while (tmp->next != head)
		tmp = tmp->next;
	node->prev = tmp;
	node->next = head;
	tmp->next = node;
	head->prev = node;
}

void	free_all(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!head)
		return ;
	tmp = head->next;
	while (tmp != head)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(head);
}
