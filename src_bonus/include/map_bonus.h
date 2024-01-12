/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_bonus.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:37:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2024/01/12 15:08:21 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H
# include <stdlib.h>
# include <stdbool.h>
# include "../../libft/libft.h"
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define START 'P'
# define FOE 'F'
# define CHARSET "01CEPF"

typedef struct s_lst	t_lst;

typedef struct s_map
{
	char	*map;
	size_t	map_len;
	size_t	line_len;
	size_t	column_len;
	int		start_index;
	int		exit_index;
	t_lst	*coll_lst;
	int		coll_count;
	t_lst	*foe_lst;
}	t_map;

extern t_map	*parse_map(char *path);
extern t_map	*init_map(t_map *map);
extern char		*put_and_remove(char **dst, char *src);
extern int		chrset(char c, const char *set);
extern void		print_map(t_map *map);
extern bool		check_special_chars(t_map *map, size_t index);
extern void		free_map(t_map *map);

#endif
