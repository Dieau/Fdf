/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:50:30 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:28:58 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_memory(t_object *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_axis[i]);
		i++;
	}
	free (data -> z_axis);
	free(data);
}

void	strfree(char **tab)
{
	if (tab && *tab)
	{
		free(*tab);
		*tab = NULL;
	}
}

void	freetab(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		strfree(&argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
}

//Lorsque l'event destroy est reçu
//Destroy la fenêtre, free le nécéssaire et quitte le programme
int	close_window(t_object *data)
{
	(void)data;
	mlx_destroy_window(data->mlx, data->win);
	free_memory(data);
	exit(0);
	return (0);
}
