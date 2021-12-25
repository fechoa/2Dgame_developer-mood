/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:51:07 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/08 11:03:15 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	putstr(char *str, int fd)
{
	size_t	i;

	i = -1;
	while (str[++i] != '\0')
		write(fd, &str[i], 1);
	return (i);
}
