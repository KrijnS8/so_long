/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 15:03:31 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 15:37:52 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H
# include "system_bonus.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	step_count;
	int	anim_index;
	int	reverse;
}	t_player;

void	init_player(t_sys *data);
void	move_player(t_sys *data, int x, int y);
void	draw_player(t_sys *data, t_img *buf);
void	load_player(t_sys *data);

#endif
