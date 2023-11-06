/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kschelvi <kschelvi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 13:37:10 by kschelvi      #+#    #+#                 */
/*   Updated: 2023/11/06 17:36:50 by kschelvi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
# include <stdlib.h>
# include "../Libft/libft.h"
# include "../include/ft_error.h"
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

extern t_map	*ft_parse_map(char *path);
extern t_map	*ft_init_map(t_map *map);
extern char		*ft_put_and_remove(char **dst, char *src);
extern int		ft_chrset(char c, const char *set);
extern void		ft_print_map(t_map *map);
extern void		ft_map_error(t_error error, t_map *map);

#endif
