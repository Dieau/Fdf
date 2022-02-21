/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:18:16 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/15 11:39:23 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	readed;
	int	i;

	i = 0;
	*line = malloc(4 * 1024 * 1024);
	if (!line)
		return (-1);
	readed = read(fd, *line + i, 1);
	while (readed > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
		readed = read(fd, *line + i, 1);
	}
	(*line)[i] = '\0';
	return (readed);
}
