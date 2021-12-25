/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:08:34 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_length_rows(const char *map_str)
{
	int		i;
	size_t	count;
	size_t	tmp;

	i = -1;
	count = 0;
	tmp = 0;
	while (map_str[++i])
	{
		if (map_str[i] != '\n')
			count++;
		else if ((map_str[i] == '\n' || map_str[i + 1] == '\0') && tmp == 0)
		{
			tmp = count;
			count = 0;
			continue ;
		}
		else if ((map_str[i] == '\n' || map_str[i + 1] == '\0') && tmp != count)
			return (print_error_rows());
		else if (map_str[i] == '\n')
			count = 0;
	}
	return (true);
}

bool	check_rectangle(t_map *map)
{
	int	i;
	int	rows;
	int	columns;

	i = -1;
	rows = 0;
	columns = 0;
	while (map->string[++i])
	{
		if (rows == 0 && map->string[i] == '\n')
			columns = i + 1;
		if (map->string[i] == '\n' || map->string[i + 1] == '\0')
			rows++;
	}
	map->height = rows;
	map->width = columns - 1;
	if (columns <= rows)
		return (print_error_rectangle());
	return (true);
}

bool	check_value_subj(const char *map_str)
{
	int	exit;
	int	coins;
	int	player;

	exit = 0;
	player = 0;
	coins = 0;
	while (*map_str)
	{
		if (*map_str == EXIT_S)
			exit++;
		if (*map_str == COIN_S)
			coins++;
		if (*map_str == PLAYER_S)
			player++;
		map_str++;
	}
	if (exit != 1)
		return (print_error_exit());
	if (player != 1)
		return (print_error_player());
	if (coins < 1)
		return (print_error_coins());
	return (true);
}

bool	check_valid_map(t_map *map)
{
	if (check_length_rows(map->string) == false)
		return (false);
	if (check_allow_symbols(map->string) == false)
		return (false);
	if (check_correct_walls(map->string) == false)
		return (false);
	if (check_rectangle(map) == false)
		return (false);
	if (check_value_subj(map->string) == false)
		return (false);
	return (true);
}

bool	check_map(t_map *map, char *filename)
{
	int		fd;
	char	buffer;

	putstr(MAP_START, 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error_open());
	while (read(fd, &buffer, 1))
		map->string = charjoin(map->string, buffer);
	if (close(fd) < 0)
		return (print_error_close());
	if (map->string == NULL || lenstr(map->string) <= 0)
		return (print_error_empty_map());
	if (check_valid_map(map) == false)
		return (false);
	putstr(GREEN_COLOR, 1);
	putstr(MAP_END, 1);
	putstr(RESET_COLOR, 1);
	return (true);
}
