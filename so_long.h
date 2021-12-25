/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:51:42 by a1111             #+#    #+#             */
/*   Updated: 2021/11/08 12:57:26 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Libraries */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdarg.h>
# include "mlx.h"

/* Colors */
# define RED_COLOR "\033[0;31m"
# define GREEN_COLOR "\033[0;32m"
# define PURPLE_COLOR "\033[0;35m"
# define RESET_COLOR  "\033[0m"

/* Progress */
# define INIT_START  "Initialize...\n"
# define INIT_END  "Structures are initialized\n"
# define MAP_START  "Checking map...\n"
# define MAP_END  "Map is valid\n"
# define FREE_START  "Free...\n"
# define FREE_END  "It\'s okay, the memory is cleared\n"

/* Texts errors */
# define PRINT_ERROR_ARGS "Wrong number of arguments...\nTry again!:)\n"
# define PRINT_ERROR_OPEN "Error...\nI can't open this file! Check it\n"
# define PRINT_ERROR_CLOSE "Error...\nI can't close this file! Check it\n"
# define PRINT_ERROR_EMPTY_MAP "Error...\nThis map is empty! Check it\n"
# define PRINT_ERROR_UNKNOWN_MAP_SYM "Error...\nThere are unidentified \
symbols on the map! Check it\n"
# define PRINT_ERROR_WALLS "Error...\nWalls on the map are incorrect! \
Check it\n"
# define PRINT_ERROR_ROWS "Error...\nThe lines of your map are of different \
lengths! Check it\n"
# define PRINT_ERROR_RECT "Error...\nYour map is not rectangular! Check it\n"
# define PRINT_ERROR_EXIT "Error...\nThe number of outputs on the map is \
incorrect! Check it\n"
# define PRINT_ERROR_PLAYER "Error...\nThe number of players on the map is \
incorrect! Check it\n"
# define PRINT_ERROR_COINS "Error...\nThere is no coins out on the map! \
Check it\n"

/* System macros */
# define INIT_CH 2
# define BIT_PIX 32
# define FAILURE 1
# define ERROR_FUNC -1
# define SUCCESS 0
# define SUCCESS_ARGS 2
# define ERROR_FD 2
# define S 340

/* Buttons */
# define UP_KEY 13
# define RIGHT_KEY 2
# define DOWN_KEY 1
# define LEFT_KEY 0
# define ESC_KEY 53

/* Map instructions */
# define EXIT_S 'E'
# define EMPTY_S '0'
# define PLAYER_S 'P'
# define WALL_S '1'
# define COIN_S 'C'
# define FOG_S 'M'

/* Structs */
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}					t_vars;

typedef struct s_map
{
	int		width;
	int		height;
	char	*string;
}					t_map;

typedef struct s_sprites
{
	void	*bg;
	void	*player_left;
	void	*player_right;
	void	*exit;
	void	*coin;
	void	*wall;
	void	*fog;
}					t_sprites;

/* Errors functions */
int			putstr(char *str, int fd);
int			print_error_args(void);
bool		print_error_open(void);
bool		print_error_close(void);
bool		print_error_empty_map(void);
bool		print_error_rows(void);
bool		print_error_walls(void);
bool		print_error_exit(void);
bool		print_error_player(void);
bool		print_error_coins(void);
bool		print_error_rectangle(void);

/* Parsing map */
size_t		lenstr(const char *str);
char		*charjoin(char *s1, char ch);
bool		check_allow_symbols(const char *str);
bool		find_lb(const char *str);
bool		check_correct_walls(const char *map_str);
bool		check_length_rows(const char *map_str);
bool		check_rectangle(t_map *map);
bool		check_value_subj(const char *map_str);
bool		check_valid_map(t_map *map);
bool		check_map(t_map *map, char *filename);

/* Initialize structures */
t_sprites	*init_sprites(void *mlx);
t_map		*init_map_struct(void);
t_vars		*init_vars(void);
int			free_all(t_map *map, t_vars *vars, t_sprites *sprites);

/* Movement */
int			movement(int keycode, t_map *map);
int			left_movement(t_map *map, bool *player_type);
int			right_movement(t_map *map, bool *player_type);
int			up_movement(t_map *map, bool *player_type);
int			down_movement(t_map *map, bool *player_type);

/* Game interface */
void		*choice_sprite(char ch, t_sprites *sprites, bool init_player);
bool		is_need_fog(t_map *map, int i);
void		paint_loop(t_vars *vars, t_sprites *sprites, t_map *map,
				bool player_type);
int			count_coins(void);
int			is_game_end(const char *map_str);
int			close_window(void *del);
int			get_position_player(char *map_str);

#endif