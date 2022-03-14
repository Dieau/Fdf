/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:29:53 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:25:55 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"
#include <fcntl.h>

//Parse la map en hauteur pour reoturner la height
int	get_height(char *file)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("INVALID FILE\n", 1);
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	close (fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("INVALID FILE\n", 1);
	if (get_next_line(fd, &line) < 1)
		error_exit("INVALID FILE\n", 1);
	width = get_count_words(line, ' ');
	free(line);
	close (fd);
	return (width);
}

//Alloue la place pour tous les points parsés dans un double tab d'int
void	memory_z(t_object *data)
{
	int	i;

	i = 0;
	data->z_axis = (int **) malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_axis)
		error_exit("MALLOC ERROR\n", 1);
	i = 0;
	while (i < data->height)
	{
		data->z_axis[i] = (int *) malloc(sizeof(int) * (data->width + 1));
		if (!data->z_axis[i])
			error_exit("MALLOC ERROR\n", 1);
		i++;
	}
}

//Remplit le double tableau d'int avec les valeurs de la map
void	fill_z(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		error_exit("MALLOC ERROR\n", 1);
	check_map(nums);
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}

//Déniche la taille (width, height)
//Alloue l'espace nécéssaire
//Remplit un tableau avec les valeurs de la map dans la struct
void	read_from_file(char *file, t_object *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(file);
	data->width = get_width(file);
	memory_z(data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("INVALID FILE\n", 1);
	while (get_next_line(fd, &line) > 0)
	{
		fill_z(data->z_axis[i], line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}
