/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 15:03:31 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 12:41:05 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H
# include "system_bonus.h"

# define P_TEXTURE_PATH "./src_bonus/resources/player/"

typedef struct s_player
{
	int		x;
	int		y;
	int		step_count;
	int		anim_index;
	double	last_tick;
	int		reverse;
}	t_player;

void	init_player(t_sys *data);
void	move_player(t_sys *data, int x, int y);
void	draw_player(t_sys *data, t_img *buf);
void	load_player(t_sys *data);
void	check_collision(t_sys *data);
void	load_player_rev(t_sys *data);

#endif
