/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:30:54 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:07:56 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	lenstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*charjoin(char *s1, char ch)
{
	char	*result;
	int		i;

	i = -1;
	if (s1 == NULL)
	{
		result = (char *) malloc(sizeof(char) * INIT_CH);
		if (result == NULL)
			return (NULL);
		result[0] = ch;
		result[1] = '\0';
	}
	else
	{
		result = (char *) malloc(lenstr(s1) + INIT_CH);
		if (result == NULL)
			return (NULL);
		while (s1[++i])
			result[i] = s1[i];
		result[i++] = ch;
		result[i] = '\0';
		free(s1);
	}
	return (result);
}

bool	check_allow_symbols(const char *str)
{
	while (*str)
	{
		if (*str != EMPTY_S && *str != WALL_S && *str != COIN_S
			&& *str != EXIT_S && *str != PLAYER_S && *str != '\n')
		{
			putstr(RED_COLOR, 2);
			putstr(PRINT_ERROR_UNKNOWN_MAP_SYM, 2);
			putstr(RESET_COLOR, 2);
			return (false);
		}
		str++;
	}
	return (true);
}

bool	find_lb(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (true);
		str++;
	}
	return (false);
}

bool	check_correct_walls(const char *map_str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map_str[++i])
	{
		if (map_str[i] == '\n')
		{
			j++;
			continue ;
		}
		if (j == 0 && map_str[i] != WALL_S)
			return (print_error_walls());
		else if (j != 0 && find_lb(&map_str[i]) == false
			&& map_str[i] != WALL_S)
			return (print_error_walls());
		else if (j != 0 && (map_str[i - 1] == '\n'
				|| map_str[i + 1] == '\n') && map_str[i] != WALL_S)
			return (print_error_walls());
		else if (j != 0 && map_str[i + 1] == '\0' && map_str[i] != WALL_S)
			return (print_error_walls());
	}
	return (true);
}
