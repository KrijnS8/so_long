/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 13:59:25 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/09 12:55:29 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_BONUS_H
# define SYSTEM_BONUS_H
# include <X11/keysym.h>
# include "error_bonus.h"

# define PROGRAM_NAME "so_long"

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_anim	t_anim;

typedef struct s_img
{
	void	*texture;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sys
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_player	*player_data;
	t_img		*frame_buf;
	t_map		*map;
	t_anim		*player;
	t_anim		*player_rev;
	t_anim		*collectible;
	t_img		*wall;
	t_img		*floor;
	t_img		*exit;
	t_img		*bg;
}	t_sys;

void	init_system(t_sys	*data);
int		destroy_system(t_sys *data);
void	system_error(t_sys *data, t_error error);
int		handle_input(int keysym, t_sys *data);
void	load_frame_buffer(t_sys *data);
void	destroy_frame_buffer(t_sys *data);

#endif
