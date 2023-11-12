/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   system.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 13:59:25 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 18:26:24 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H
# include <X11/keysym.h>
# include "map.h"

# define PROGRAM_NAME "so_long"

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK 1L<<0
# define KEY_RELEASE_MASK 1L<<1
# define BUTTON_PRESS_MASK 1L<<2
# define BUTTON_RELEASE_MASK 1L<<3
# define ENTER_WINDOW_MASK 1L<<4
# define LEAVE_WINDOW_MASK 1L<<5
# define POINTER_MOTION_MASK 1L<<6
# define POINTER_MOTION_HINT_MASK 1L<<7
# define BUTTON1_MOTION_MASK 1L<<8
# define BUTTON2_MOTION_MASK 1L<<9
# define BUTTON3_MOTION_MASK 1L<<10
# define BUTTON4_MOTION_MASK 1L<<11
# define BUTTON5_MOTION_MASK 1L<<12
# define BUTTON_MOTION_MASK 1L<<13
# define KEYMAP_STATE_MASK 1L<<14
# define EXPOSURE_MASK 1L<<15
# define VISIBILITY_CHANGE_MASK 1L<<16
# define STRUCTURE_NOTIFY_MASK 1L<<17
# define RESIZE_REDIRECT_MASK 1L<<18
# define SUBSTRUCTURE_NOTIFY_MASK 1L<<19
# define SUBSTRUCTURE_REDIRECT_MASK 1L<<20
# define FOCUS_CHANGE_MASK 1L<<21
# define PROPERTY_CHANGE_MASK 1L<<22
# define COLORMAP_CHANGE_MASK 1L<<23
# define OWNER_GRAB_BUTTON_MASK 1L<<24

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

typedef struct s_player
{
	int	x;
	int	y;
	int	step_count;
}	t_player;

typedef struct s_sys
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_player	*player_data;
	t_map		*map;
	t_img		*player;
	t_img		*collectible;
	t_img		*wall;
	t_img		*floor;
	t_img		*exit;
	t_img		*background;
	
}	t_sys;

void	init_system(t_sys	*data);
void	init_player(t_sys *data);
int 	destroy_system(t_sys *data);
void	system_error(t_sys *data, t_error error);
int		handle_input(int keysym, t_sys *data);

#endif
