/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:32:57 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:21:42 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//Parse la map en largeur pour retourner la width
int	get_count_words(char *line, char ch)
{
	int	count_words;

	count_words = 0;
	while (*line == ch && *line)
		++line;
	while (*line)
	{
		++count_words;
		while (*line != ch && *line)
			++line;
		while (*line == ch && *line)
			++line;
	}
	return (count_words);
}

void	print_menu(t_object *data)
{
	mlx_string_put(data->mlx, data->win,
		65, 20, 0xEF8633, "COMMANDS");
	mlx_string_put(data->mlx, data->win,
		65, 60, 0xEAEAEA, "Zoom: + / -");
	mlx_string_put(data->mlx, data->win, 65,
		80, 0xEAEAEA, "Zoom Z: z / x");
	mlx_string_put(data->mlx, data->win, 65,
		100, 0xEAEAEA, "Rotate: < / >");
	mlx_string_put(data->mlx, data->win, 65,
		120, 0xEAEAEA, "Move: Arrows");
	mlx_string_put(data->mlx, data->win, 65,
		140, 0xEAEAEA, "Set to default: R");
	mlx_string_put(data->mlx, data->win, 65,
		180, 0xEF8633, "Projection");
	mlx_string_put(data->mlx, data->win, 65,
		220, 0xEAEAEA, "Isometric view: I");
	mlx_string_put(data->mlx, data->win, 65,
		240, 0xEAEAEA, "Parallel view: P");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// Initialise les données de l'objet
// Set les offsets et l'angle par défault
// Print le menu et le point de vue initial
void	init(t_object *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx,
			WIDTH, HEIGHT, "FDF / alakhdar");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	data->zoom = 25;
	data->z_zoom = 1;
	data->shift_x = 825;
	data->shift_y = 325;
	data->alpha = 0.523599;
	data->is_iso = true;
	drawmap(data);
	print_menu(data);
}

//Un hook pour les keycodes
//Un hook pour le destroy
int	main(int argc, char **argv)
{
	t_object	*data;

	if (argc != 2)
		error_exit("ERROR : ONLY ONE ARGUMENT ALLOWED\n", 0);
	data = (t_object *) malloc(sizeof(t_object));
	if (!data)
		error_exit("MALLOC ERROR\n", 1);
	read_from_file(argv[1], data);
	init(data);
	mlx_hook(data->win, 17, !1L << 0, close_window, data);
	mlx_hook(data->win, 2, 0, pressed_key, data);
	mlx_loop(data->mlx);
	return (0);
}
