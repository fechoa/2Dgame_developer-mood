/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_interface_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 12:57:38 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*choice_sprite(char ch, t_sprites *sprites, bool init_player)
{
	static t_sprites	*local;

	if (sprites != NULL)
		local = sprites;
	if (ch == EMPTY_S)
		return (local->bg);
	else if (ch == FOG_S)
		return (local->fog);
	else if (ch == EXIT_S)
		return (local->exit);
	else if (ch == WALL_S)
		return (local->wall);
	else if (ch == COIN_S)
		return (local->coin);
	else if (ch == PLAYER_S && init_player == false)
		return (local->player_right);
	else if (ch == PLAYER_S && init_player == true)
		return (local->player_left);
	return (NULL);
}

bool	is_need_fog(t_map *map, int i)
{
	if (map->string[i] != PLAYER_S && map->string[i + 1] != PLAYER_S
		&& map->string[i + 2] != PLAYER_S && map->string[i - 1] != PLAYER_S
		&& map->string[i - 2] != PLAYER_S
		&& map->string[i + 1 + map->width] != PLAYER_S
		&& map->string[i + map->width] != PLAYER_S
		&& map->string[i + map->width - 1] != PLAYER_S
		&& map->string[i + 2 + map->width] != PLAYER_S
		&& map->string[i + 3 + map->width] != PLAYER_S
		&& map->string[i - 1 - map->width] != PLAYER_S
		&& map->string[i - 2 - map->width] != PLAYER_S
		&& map->string[i - 3 - map->width] != PLAYER_S
		&& map->string[i - map->width] != PLAYER_S
		&& map->string[i - map->width + 1] != PLAYER_S
		&& map->string[i + map->width + map->width] != PLAYER_S
		&& map->string[i + map->width + map->width + 1] != PLAYER_S
		&& map->string[i + map->width + map->width + 2] != PLAYER_S
		&& map->string[i + map->width + map->width + 3] != PLAYER_S
		&& map->string[i + map->width + map->width + 4] != PLAYER_S
		&& map->string[i - map->width - map->width] != PLAYER_S
		&& map->string[i - map->width - map->width - 1] != PLAYER_S
		&& map->string[i - map->width - map->width - 2] != PLAYER_S
		&& map->string[i - map->width - map->width - 3] != PLAYER_S
		&& map->string[i - map->width - map->width - 4] != PLAYER_S)
		return (true);
	return (false);
}

void	paint_loop(t_vars *vars, t_sprites *sprites, t_map *map,
	bool player_type)
{
	static t_vars	locals;
	void			*img;
	int				i;

	if (vars != NULL)
	{
		locals.mlx = vars->mlx;
		locals.win = vars->win;
	}
	i = -1;
	while (map->string[++i] != '\0')
	{
		mlx_put_image_to_window(locals.mlx, locals.win,
			choice_sprite('0', sprites, player_type), BIT_PIX
			* (i % (map->width + 1)), S + BIT_PIX * (i / (map->width + 1)));
		img = choice_sprite(map->string[i], sprites, player_type);
		if (img != NULL && map->string[i] != EMPTY_S)
			mlx_put_image_to_window(locals.mlx, locals.win, img, BIT_PIX
				* (i % (map->width + 1)), S + BIT_PIX * (i / (map->width + 1)));
		if (is_need_fog(map, i) == true)
			mlx_put_image_to_window(locals.mlx, locals.win,
				choice_sprite('M', sprites, player_type), BIT_PIX
				* (i % (map->width + 1)), S + BIT_PIX
				* (i / (map->width + 1)));
	}
}

int	count_coins(void)
{
	static int	coins;

	return (++coins);
}

int	is_game_end(const char *map_str)
{
	int	i;

	i = -1;
	while (map_str[++i])
		if (map_str[i] == COIN_S)
			return (false);
	return (true);
}
