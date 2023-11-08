/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:37:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/08 15:38:19 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include "../Libft/libft.h"
# include "error.h"
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START 'P'
# define CHARSET "01CEP"

typedef struct s_map {
	char	*map;
	size_t	map_len;
	size_t	line_len;
	size_t	column_len;
	int		start_index;
	int		exit_index;
} t_map;

extern t_map	*parse_map(char *path);
extern t_map	*init_map(t_map *map);
extern char		*put_and_remove(char **dst, char *src);
extern int		chrset(char c, const char *set);
extern void		print_map(t_map *map);
extern void		map_error(t_error error, t_map *map);

#endif
