/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectible_bonus.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 13:32:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/08 17:59:41 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIBLE_BONUS_H
# define COLLECTIBLE_BONUS_H

typedef struct s_lst	t_lst;
typedef struct s_sys	t_sys;

typedef struct s_collectible
{
	int	x;
	int	y;
	int	show;
}	t_collectible;

t_collectible	*new_collectible(int x, int y);
void			free_collectible(void *ptr);
t_lst			*is_on_collectible(t_sys *data);

#endif
