/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   foe_bonus.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 14:14:06 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 14:18:20 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOE_BONUS_H
# define FOE_BONUS_H

# define F_TEXTURE_PATH "./src_bonus/resources/foe/"

typedef struct s_lst	t_lst;
typedef struct s_sys	t_sys;

typedef struct s_foe
{
	int		x;
	int		y;
	int		anim_index;
	double	last_tick;
}	t_foe;

void	draw_foe(t_sys *data, t_img *buf);
t_foe	*new_foe(int x, int y);
void	free_foe(void *ptr);
t_lst	*is_on_foe(t_sys *data);
void	load_foe(t_sys *data);

#endif
