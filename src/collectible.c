/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 14:26:50 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/13 14:48:18 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/collectible.h"
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

void	free_collectible(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}
