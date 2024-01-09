/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 14:38:47 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 17:12:05 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DFS_H
# define DFS_H

typedef struct s_map		t_map;
typedef struct s_dfs_stack	t_dfs_stack;

typedef struct s_dfs_cell
{
	int	x;
	int	y;
}	t_dfs_cell;

typedef struct s_dfs_stack
{
	t_dfs_cell	*content;
	t_dfs_stack	*next;
}	t_dfs_stack;

// Stack functions
t_dfs_cell	*dfs_create_cell(int x, int y);
int			dfs_push(t_dfs_stack **top, t_dfs_cell *content);
t_dfs_cell	*dfs_pop(t_dfs_stack **top);
int			dfs_exists(t_dfs_stack *top, int x, int y);

// Algorithm functions
int			dfs(t_map *map);

#endif
