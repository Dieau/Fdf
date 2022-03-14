/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:15:31 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:44:05 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/alias.h"
#include <math.h>

void	set_params(t_position *bline, t_object *data)
{
	int				z;
	int				z1;

	z = data->z_axis[(int)bline->y][(int)bline->x] * data->z_zoom;
	z1 = data->z_axis[(int)bline->y1][(int)bline->x1] * data->z_zoom;
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000 + (z * 0.9);
	else if (z < 0 || z1 < 0)
		data->color = 0x610000;
	else
		data->color = 0xAB0000;
	bline->x *= data->zoom;
	bline->y *= data->zoom;
	bline->x1 *= data->zoom;
	bline->y1 *= data->zoom;
	if (data->is_iso)
	{
		isometry (&bline->x, &bline->y, z, data->alpha);
		isometry (&bline->x1, &bline->y1, z1, data->alpha);
	}
	bline->x += data->shift_x;
	bline->y += data->shift_y;
	bline->x1 += data->shift_x;
	bline->y1 += data->shift_y;
}

//Algorithme de tracé de points
void	bresenham(t_position bline, t_object *data)
{
	float	x_step;
	float	y_step;
	int		max_step;

	set_params(&bline, data);
	x_step = bline.x1 - bline.x;
	y_step = bline.y1 - bline.y;
	max_step = max_ab(abs_a(x_step), abs_a(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while ((int)(bline.x - bline.x1) || (int)(bline.y - bline.y1))
	{
		my_mlx_pixel_put(&data->img, bline.x, bline.y, data->color);
		bline.x += x_step;
		bline.y += y_step;
	}
}

t_position	get_blinex(t_position bline, int x, int y)
{
	bline.x = x;
	bline.y = y;
	bline.x1 = x + 1;
	bline.y1 = y;
	return (bline);
}

t_position	get_bliney(t_position bline, int x, int y)
{
	bline.x = x;
	bline.y = y;
	bline.x1 = x;
	bline.y1 = y + 1;
	return (bline);
}

void	drawmap(t_object *data)
{
	int			x;
	int			y;
	t_position	bline;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < (data->width) - 1)
			{
				bline = get_blinex(bline, x, y);
				bresenham(bline, data);
			}
			if (y < (data -> height) - 1)
			{
				bline = get_bliney(bline, x, y);
				bresenham(bline, data);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
