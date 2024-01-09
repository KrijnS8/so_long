/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_bonus.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:32:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 12:57:01 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_BONUS_H
# define COLLECTIBLE_BONUS_H

# define C_TEXTURE_PATH "./src_bonus/resources/collectible/"

typedef struct s_lst	t_lst;
typedef struct s_sys	t_sys;

typedef struct s_collectible
{
	int		x;
	int		y;
	int		collected;
	int		anim_index;
	double	last_tick;
}	t_collectible;

void			draw_collectibles(t_sys *data, t_img *buf);
t_collectible	*new_collectible(int x, int y);
void			free_collectible(void *ptr);
t_lst			*is_on_collectible(t_sys *data);
void			load_collectible(t_sys *data);

#endif
