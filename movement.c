/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:51:23 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	left_movement(t_map *map, bool *player_type)
{
	int	pos_player;

	*player_type = true;
	pos_player = get_position_player(map->string);
	if (map->string[pos_player - 1] == EXIT_S
		&& is_game_end(map->string) == *player_type)
		exit(0);
	if (map->string[pos_player - 1] == COIN_S)
	{
		count_coins();
		map->string[pos_player - 1] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	else if (map->string[pos_player - 1] == EMPTY_S)
	{
		map->string[pos_player - 1] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	return (SUCCESS);
}

int	right_movement(t_map *map, bool *player_type)
{
	int	pos_player;

	*player_type = false;
	pos_player = get_position_player(map->string);
	if (map->string[pos_player + 1] == EXIT_S
		&& is_game_end(map->string) == true)
		exit(0);
	if (map->string[pos_player + 1] == COIN_S)
	{
		count_coins();
		map->string[pos_player + 1] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	else if (map->string[pos_player + 1] == EMPTY_S)
	{
		map->string[pos_player + 1] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	return (SUCCESS);
}

int	up_movement(t_map *map, bool *player_type)
{
	int	pos_player;
	int	pos_next;

	pos_player = get_position_player(map->string);
	pos_next = pos_player - 1 - map->width;
	if (map->string[pos_next] == EXIT_S && is_game_end(map->string) == true)
		exit(0);
	if (map->string[pos_next] == COIN_S)
	{
		count_coins();
		map->string[pos_next] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}		
	else if (map->string[pos_next] == EMPTY_S)
	{
		map->string[pos_next] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	return (SUCCESS);
}

int	down_movement(t_map *map, bool *player_type)
{
	int	pos_player;
	int	pos_next;

	pos_player = get_position_player(map->string);
	pos_next = pos_player + 1 + map->width;
	if (map->string[pos_next] == EXIT_S && is_game_end(map->string) == true)
		exit(0);
	if (map->string[pos_next] == COIN_S)
	{
		count_coins();
		map->string[pos_next] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}		
	else if (map->string[pos_next] == EMPTY_S)
	{
		map->string[pos_next] = PLAYER_S;
		map->string[pos_player] = EMPTY_S;
		paint_loop(NULL, NULL, map, player_type);
	}
	return (SUCCESS);
}

int	movement(int keycode, t_map *map)
{
	static bool	player;
	static int	i = 0;

	if (i == 0)
		player = false;
	else
	{
		printf(PURPLE_COLOR);
		printf("Moves = %d\n", i);
		printf(RESET_COLOR);
	}
	if (keycode == UP_KEY && up_movement(map, &player) == SUCCESS)
		paint_loop(NULL, NULL, map, player);
	else if (keycode == RIGHT_KEY && right_movement(map, &player) == SUCCESS)
		paint_loop(NULL, NULL, map, player);
	else if (keycode == DOWN_KEY && down_movement(map, &player) == SUCCESS)
		paint_loop(NULL, NULL, map, player);
	else if (keycode == LEFT_KEY && left_movement(map, &player) == SUCCESS)
		paint_loop(NULL, NULL, map, player);
	else if (keycode == ESC_KEY)
		exit(0);
	i++;
	return (SUCCESS);
}
