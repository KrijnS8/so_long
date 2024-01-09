/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs_stack_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 14:48:46 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 17:38:10 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/dfs_bonus.h"
#include "stdlib.h"

t_dfs_cell	*dfs_create_cell(int x, int y)
{
	t_dfs_cell	*cell;

	cell = (t_dfs_cell *)malloc(sizeof(t_dfs_cell));
	if (!cell)
		return (NULL);
	cell->x = x;
	cell->y = y;
	return (cell);
}

static t_dfs_stack	*dfs_create_node(t_dfs_cell *content)
{
	t_dfs_stack	*node;

	node = (t_dfs_stack *)malloc(sizeof(t_dfs_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	dfs_push(t_dfs_stack **top, t_dfs_cell *content)
{
	t_dfs_stack	*node;

	if (content == NULL)
		return (0);
	node = dfs_create_node(content);
	if (!node)
		return (free(content), 0);
	node->next = *top;
	*top = node;
	return (1);
}

t_dfs_cell	*dfs_pop(t_dfs_stack **top)
{
	t_dfs_stack	*tmp;
	t_dfs_cell	*cell;

	if (!*top)
		return (NULL);
	cell = (*top)->content;
	tmp = *top;
	*top = (*top)->next;
	free(tmp);
	return (cell);
}

int	dfs_exists(t_dfs_stack *top, int x, int y)
{
	t_dfs_cell	*current;

	while (top != NULL)
	{
		current = (t_dfs_cell *)top->content;
		if (x == current->x && y == current->y)
			return (1);
		top = top->next;
	}
	return (0);
}
