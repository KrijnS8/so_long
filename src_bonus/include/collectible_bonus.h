/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_bonus.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:32:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/17 14:00:36 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_BONUS_H
# define COLLECTIBLE_BONUS_H
# include "system_bonus.h"
# include "collectible_bonus.h"
# include "animation_bonus.h"

typedef struct s_collectible {
	int		x;
	int		y;
	int		opened;
	t_anim	*anim;
}	t_collectible;

t_collectible	*new_collectible(int x, int y);
void			free_collectible(void *ptr);
t_lst			*is_on_collectible(t_sys *data);
void			update_collectible_anim(t_sys *data);
void			start_collectible_anim(t_sys *data, t_collectible *coll);

#endif
