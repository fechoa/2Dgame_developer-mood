/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:05:08 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error_args(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_ARGS, 2);
	putstr(RESET_COLOR, 2);
	return (FAILURE);
}

bool	print_error_open(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_OPEN, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_close(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_CLOSE, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_empty_map(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_EMPTY_MAP, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}

bool	print_error_rows(void)
{
	putstr(RED_COLOR, 2);
	putstr(PRINT_ERROR_ROWS, 2);
	putstr(RESET_COLOR, 2);
	return (false);
}
