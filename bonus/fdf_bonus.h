/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:41:37 by alakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 10:38:58 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# define WIDTH 1920
# define HEIGHT 1080

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdbool.h>

typedef struct s_position
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_position;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_object
{
	t_data			img;
	int				width;
	int				height;
	int				**z_axis;
	int				z_zoom;
	int				z_max;
	int				zoom;
	int				color;
	int				shift_x;
	int				shift_y;
	float			alpha;
	bool			is_iso;
	void			*mlx;
	void			*win;
	struct timespec	curr_time;
	struct timespec	prev_time;
}				t_object;

int					pressed_key(int key, t_object *data);
int					max_ab(float a, float b);
int					get_count_words(char *line, char ch);
int					get_next_line(int fd, char **line);
void				error_exit(char *msg, int exit_code);
void				check_map(char **nums);
void				free_memory(t_object *data);
void				strfree(char **tab);
void				freetab(char **argv);
void				move_map(t_object *data, int key);
void				zoom_map(t_object *data, int key);
void				set_iso_parallel(t_object *data, int key);
void				rotate_map(t_object *data, int key);
void				zoom_z(t_object *data, int key);
void				isometry(float *x, float *y, int z, float alpha);
void				read_from_file(char *file, t_object *data);
void				set_default(t_object *data);
void				print_menu(t_object *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				drawmap(t_object *data);
float				abs_a(float a);
int					is_number(char *str);
int					get_height(char *file);
int					get_width(char *file);
int					close_window(t_object *data);
void				init(t_object *data);
void				memory_z(t_object *data);
void				fill_z(int *z_line, char *line);
void				set_params(t_position *bline, t_object *data);
void				bresenham(t_position bline, t_object *data);
char				*print_fps(t_object *data);
t_position			get_blinex(t_position bline, int x, int y);
t_position			get_bliney(t_position bline, int x, int y);

#endif