/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:49:53 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 15:57:49 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "system_bonus.h"

typedef enum e_player_state
{
	PLAYER_STATE_IDLE,
	PLAYER_STATE_RUN
}	t_player_state;

typedef struct s_player
{
	int				x;
	int				y;
	int				step_count;
	t_player_state	state;
	int				rotation;
	t_anim			*anim;
}	t_player;

void	move_player(t_sys *data, int x, int y);
void	init_player(t_sys *data);
void	update_player_anim(t_sys *data, t_player_state state);

#endif
