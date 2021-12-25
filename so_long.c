/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:51:23 by a1111             #+#    #+#             */
/*   Updated: 2021/11/08 12:09:07 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_sprites	*sprites;
	t_vars		*vars;
	t_map		*map;

	if (argc != SUCCESS_ARGS)
		return (print_error_args());
	map = init_map_struct();
	vars = init_vars();
	vars->mlx = mlx_init();
	sprites = init_sprites(vars->mlx);
	if (check_map(map, argv[1]) == false)
		return (free_all(map, vars, sprites) + FAILURE);
	vars->win = mlx_new_window(vars->mlx, BIT_PIX * map->width,
			BIT_PIX * map->height * 3, "Coderka 1995");
	paint_loop(vars, sprites, map, false);
	mlx_key_hook(vars->win, &movement, map);
	mlx_hook(vars->win, 17, (1L << 17), close_window, 0);
	mlx_loop(vars->mlx);
	free_all(map, vars, sprites);
	return (SUCCESS);
}
