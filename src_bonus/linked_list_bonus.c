/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_list_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:44:02 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 14:27:08 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/linked_list_bonus.h"
#include <stdlib.h>

t_lst	*lst_new(void *content)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_lst	*lst_last(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_lst **lst, t_lst *node)
{
	t_lst	*last;

	if (node == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	last = lst_last(*lst);
	last->next = node;
	node->prev = last;
}

void	lst_del_node(t_lst **lst, t_lst	*node, void (*del)(void*))
{
	t_lst	*prev;
	t_lst	*next;

	prev = node->prev;
	next = node->next;
	if (prev == NULL)
	{
		if (next != NULL)
			next->prev = NULL;
		*lst = next;
	}
	else
	{
		prev->next = next;
		if (next != NULL)
			next->prev = prev;
	}
	del(node->content);
	free(node);
}

void	lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*current;
	t_lst	*next;

	if (*lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
