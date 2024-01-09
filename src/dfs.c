/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 15:11:15 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 17:25:48 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./include/dfs.h"
#include "./include/map.h"
#include "../libft/libft.h"

static int	dfs_is_valid(t_map *map, t_dfs_stack *visited, int x, int y)
{
	int	index;

	index = y * map->line_len + x;
	if (map->map[index] == WALL)
		return (0);
	if (dfs_exists(visited, x, y))
		return (0);
	return (1);
}

static void	dfs_add_valid_neighbors(t_map *map, t_dfs_cell *cell, \
										t_dfs_stack **stack, \
										t_dfs_stack **visited)
{
	if (dfs_is_valid(map, *visited, cell->x + 1, cell->y))
		dfs_push(stack, dfs_create_cell(cell->x + 1, cell->y));
	if (dfs_is_valid(map, *visited, cell->x - 1, cell->y))
		dfs_push(stack, dfs_create_cell(cell->x - 1, cell->y));
	if (dfs_is_valid(map, *visited, cell->x, cell->y + 1))
		dfs_push(stack, dfs_create_cell(cell->x, cell->y + 1));
	if (dfs_is_valid(map, *visited, cell->x, cell->y - 1))
		dfs_push(stack, dfs_create_cell(cell->x, cell->y - 1));
}

static void	dfs_free_stack(t_dfs_stack *stack)
{
	t_dfs_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp->content);
		free(tmp);
	}
}

int	dfs(t_map *map)
{
	static t_dfs_stack	*stack = NULL;
	static t_dfs_stack	*visited = NULL;
	int					x;
	int					y;
	t_dfs_cell			*current_cell;

	if (stack == NULL && visited == NULL)
	{
		x = map->start_index % map->line_len;
		y = map->start_index / map->line_len;
		if (!dfs_push(&stack, dfs_create_cell(x, y)))
			return (-1);
	}
	current_cell = dfs_pop(&stack);
	if (current_cell->x == map->exit_index % map->line_len && \
			current_cell->y == map->exit_index / map->line_len)
		return (free(current_cell), dfs_free_stack(stack), \
					dfs_free_stack(visited), 1);
	dfs_push(&visited, current_cell);
	dfs_add_valid_neighbors(map, current_cell, &stack, &visited);
	if (!stack)
		return (dfs_free_stack(stack), dfs_free_stack(visited), 0);
	return (dfs(map));
}
