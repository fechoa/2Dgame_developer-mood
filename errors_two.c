/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:09:04 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	print_error_walls(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_WALLS, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_exit(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_EXIT, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_player(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_PLAYER, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_coins(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_COINS, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_rectangle(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_RECT, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}
