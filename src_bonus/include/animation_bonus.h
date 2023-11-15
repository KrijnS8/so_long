/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animation_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:42:00 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/15 14:51:37 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

// Every 20 frames we intend to update each animation
# define ANIMATION_TICK_RATE 15

typedef struct s_anim
{
	int	current_frame;
	int	frame_count;
	int	ticks_to_next;
}	t_anim;

#endif