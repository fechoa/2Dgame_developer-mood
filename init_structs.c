/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:07:32 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprites	*init_sprites(void *mlx)
{
	t_sprites	*sprites;
	int			width;
	int			height;

	sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (sprites == NULL)
		exit(1);
	sprites->bg = mlx_xpm_file_to_image(mlx, "./level.xpm", &width, &height);
	sprites->fog = mlx_xpm_file_to_image(mlx, "./fog.xpm", &width, &height);
	sprites->exit = mlx_xpm_file_to_image(mlx, "./exit.xpm", &width, &height);
	sprites->wall = mlx_xpm_file_to_image(mlx, "./wall.xpm", &width, &height);
	sprites->coin = mlx_xpm_file_to_image(mlx, "./coins.xpm", &width, &height);
	sprites->player_right = mlx_xpm_file_to_image(mlx, "./player.xpm",
			&width, &height);
	sprites->player_left = mlx_xpm_file_to_image(mlx, "./player_left.xpm",
			&width, &height);
	putstr(GREEN_COLOR, 1);
	putstr(INIT_END, 1);
	putstr(RESET_COLOR, 1);
	return (sprites);
}

t_map	*init_map_struct(void)
{
	t_map	*result;

	putstr(INIT_START, 1);
	result = (t_map *) malloc(sizeof(t_map));
	if (result == NULL)
		exit(1);
	result->height = 0;
	result->width = 0;
	result->string = NULL;
	return (result);
}

t_vars	*init_vars(void)
{
	t_vars	*result;

	result = (t_vars *) malloc(sizeof(t_vars));
	if (result == NULL)
		exit(1);
	return (result);
}

int	free_all(t_map *map, t_vars *vars, t_sprites *sprites)
{
	putstr(FREE_START, 1);
	if (map != NULL)
		free(map);
	if (vars != NULL)
		free(vars);
	if (sprites != NULL)
		free(sprites);
	putstr(GREEN_COLOR, 1);
	putstr(FREE_END, 1);
	putstr(RESET_COLOR, 1);
	return (SUCCESS);
}
