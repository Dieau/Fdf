/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:12:01 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/21 13:30:55 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/alias.h"

int	max_ab(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	abs_a(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

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
	print_menu(data);
}

int	pressed_key(int key, t_object *data)
{
	if (key == KEY_DOWN || key == KEY_UP
		|| key == KEY_LEFT || key == KEY_RIGHT)
		move_map(data, key);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		zoom_map(data, key);
	else if (key == ISO || key == PARALLEL)
		set_iso_parallel(data, key);
	else if (key == ROT_LEFT || key == ROT_RIGHT)
		rotate_map(data, key);
	else if (key == KEY_RESET)
		set_default(data);
	else if (key == KEY_PLUS_Z || key == KEY_MINUS_Z)
		zoom_z(data, key);
	else if (key == ESC)
	{
		free_memory(data);
		exit(0);
	}
	return (0);
}

char	*print_fps(t_object *data)
{
	double	delta_time;
	char	*fps;

	clock_gettime(CLOCK_MONOTONIC_RAW, &(data->curr_time));
	delta_time = (data->curr_time.tv_nsec - data->prev_time.tv_nsec) / 1000;
	fps = ft_itoa(1 / (delta_time / 1000000) + 20);
	return (fps);
}
