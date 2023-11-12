/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/08 16:41:09 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/12 18:40:33 by krijn         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../include/system.h"

int		handle_render(t_sys *system);
void    render_background(t_sys *data, t_img *buf);

#endif