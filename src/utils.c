/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:12:01 by alakhdar          #+#    #+#             */
/*   Updated: 2022/03/09 11:53:16 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/alias.h"

//Retourne le plus grand float entre a et b
int	max_ab(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

//Vérifie le signe du float
float	abs_a(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

//Paramètres de base de l'image pour un point de vue correct au lancement
//et pouvoir reset la projection
void	set_default(t_object *data)
{
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 825;
	data->shift_y = 325;
	data->alpha = 0.523599;
	data->is_iso = true;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
}

//Redirige vers la fonction appropriée en fonction du signal reçu
int	pressed_key(int key, t_object *data)
{
	if (key == ESC)
	{
		free_memory(data);
		exit(0);
	}
	return (0);
}
