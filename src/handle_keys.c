/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:43:39 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/17 14:08:46 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/alias.h"

void	move_map(t_object *data, int key)
{
	if (key == KEY_DOWN)
		data->shift_y += 15;
	if (key == KEY_UP)
		data->shift_y -= 15;
	if (key == KEY_LEFT)
		data->shift_x -= 15;
	if (key == KEY_RIGHT)
		data->shift_x += 15;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
	print_menu(data);
}

void	zoom_map(t_object *data, int key)
{
	if (key == KEY_PLUS)
		data->zoom += 1;
	if (key == KEY_MINUS && data->zoom > 1)
		data->zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
	print_menu(data);
}

void	set_iso_parallel(t_object *data, int key)
{
	if (key == ISO)
		data->is_iso = true;
	if (key == PARALLEL)
		data->is_iso = false;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
	print_menu(data);
}

void	rotate_map(t_object *data, int key)
{
	data->is_iso = true;
	if (key == ROT_RIGHT)
		data->alpha += 0.1;
	if (key == ROT_LEFT)
		data->alpha -= 0.1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
	print_menu(data);
}

void	zoom_z(t_object *data, int key)
{
	if (key == KEY_PLUS_Z)
		data -> z_zoom += 1;
	if (key == KEY_MINUS_Z && data->z_zoom > 1)
		data -> z_zoom -= 1;
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	drawmap(data);
	print_menu(data);
}
