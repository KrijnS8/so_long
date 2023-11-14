/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:32:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/14 12:57:08 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_H
# define COLLECTIBLE_H
# include "system.h"
# include "collectible.h"

typedef struct s_collectible {
	int	x;
	int	y;
	int	show;
}	t_collectible;

t_collectible	*new_collectible(int x, int y);
void			free_collectible(void *ptr);
t_lst			*is_on_collectible(t_sys *data);

#endif
