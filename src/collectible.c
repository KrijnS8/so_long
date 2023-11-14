/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:26:50 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 12:49:38 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/collectible.h"
#include "../include/system.h"
#include "../include/linked_list.h"
#include <stdlib.h>

t_collectible	*new_collectible(int x, int y)
{
	t_collectible	*new;

	new = (t_collectible *)malloc(sizeof(t_collectible));
	if (new == NULL)
		return (NULL);
	new->x = x;
	new->y = y;
	new->show = 1;
	return (new);
}

t_lst	*is_on_collectible(t_sys *data)
{
	t_player		*p_ptr;
	t_lst			*l_ptr;
	t_collectible	*c_ptr;

	p_ptr = data->player_data;
	l_ptr = data->map->coll_lst;
	while (l_ptr != NULL)
	{
		c_ptr = (t_collectible *)l_ptr->content;
		if (p_ptr->x == c_ptr->x && p_ptr->y == c_ptr->y)
			return (l_ptr);
		l_ptr = l_ptr->next;
	}
	return (NULL);
}

void	free_collectible(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
