/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:50:30 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/15 11:39:21 by alakhdar         ###   ########lyon.fr   */
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
