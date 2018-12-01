/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:59:39 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 20:24:36 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "math.h"
# include "libft.h"
# include "get_next_line.h"
# include "stdio.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "stdlib.h"

typedef struct			s_coord
{
	double				x;
	double				y;
}						t_coord;

typedef struct			s_draw
{
	double				x0;
	double				y0;
	double				x1;
	double				y1;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					color;
	int					d;
	int					d1;
	int					d2;
	int					x;
	int					y;
	int					i;

}						t_draw;

typedef struct			s_coord_data
{
	int					height;
	int					width;
	double				step_x;
	double				step_y;
	int					total_dots;
	double				cur_x;
	double				cur_y;
	int					change_x;
	int					change_y;
	void				*mlx_ptr;
	void				*win_ptr;
	int					depth;
	t_coord				*cords;
	char				*name_of_file;
}						t_coord_data;

void					init_data(char *s, t_coord_data *data);
void					reader(t_coord_data *data);
void					deal_with_coords(int num, t_coord_data *data, int j);
void					transfer_coords(t_coord_data *data);
void					conect_dots(t_coord_data *data);
void					drawline(t_coord_data *data, int one, int two);
int						deal_key(int key, t_coord_data *data);
void					move_x_right(t_coord_data *data);
void					move_x_left(t_coord_data *data);
void					move_y_up(t_coord_data *data);
void					move_y_down(t_coord_data *data);
void					change_depth_minus(t_coord_data *data);
void					change_depth_plus(t_coord_data *data);
void					xuita(t_coord_data *data, int fd, int row);
#endif
