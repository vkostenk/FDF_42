/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:00:02 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 20:24:28 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_if(t_draw *draw, t_coord_data *data)
{
	draw->d = (draw->dy << 1) - draw->dx;
	draw->d1 = draw->dy << 1;
	draw->d2 = (draw->dy - draw->dx) << 1;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			draw->x0, draw->y0, draw->color);
	draw->x = draw->x0 + draw->sx;
	draw->y = draw->y0;
	draw->i = 1;
	while (draw->i <= draw->dx)
	{
		if (draw->d > 0)
		{
			draw->d += draw->d2;
			draw->y += draw->sy;
		}
		else
			draw->d += draw->d1;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				draw->x, draw->y, draw->color);
		draw->i++;
		draw->x += draw->sx;
	}
}

void		draw_else(t_draw *draw, t_coord_data *data)
{
	draw->d = (draw->dx << 1) - draw->dy;
	draw->d1 = draw->dx << 1;
	draw->d2 = (draw->dx - draw->dy) << 1;
	draw->y = draw->y0 + draw->sy;
	draw->i = 1;
	draw->x = draw->x0;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			draw->x0, draw->y0, draw->color);
	while (draw->i <= draw->dy)
	{
		if (draw->d > 0)
		{
			draw->d += draw->d2;
			draw->x += draw->sx;
		}
		else
			draw->d += draw->d1;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
				draw->x, draw->y, draw->color);
		draw->y += draw->sy;
		draw->i++;
	}
}

void		init_draw_data(t_draw *draw, int one, int two, t_coord_data *data)
{
	draw->x0 = data->cords[one].x + data->change_x;
	draw->x1 = data->cords[two].x + data->change_x;
	draw->y0 = data->cords[one].y + data->change_y;
	draw->y1 = data->cords[two].y + data->change_y;
	draw->color = 0x7FaFF2;
	draw->dx = fabs(draw->x1 - draw->x0);
	draw->dy = fabs(draw->y1 - draw->y0);
	draw->sx = draw->x1 >= draw->x0 ? 1 : -1;
	draw->sy = draw->y1 >= draw->y0 ? 1 : -1;
}

void		drawline(t_coord_data *data, int one, int two)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	init_draw_data(draw, one, two, data);
	if (draw->dy <= draw->dx)
		draw_if(draw, data);
	else
		draw_else(draw, data);
	free(draw);
}

void		conect_dots(t_coord_data *data)
{
	int i;
	int j;
	int row;
	int prev_y;

	i = 0;
	j = 0;
	row = 0;
	while (i < data->total_dots)
	{
		if (i % data->width == 0)
			row++;
		j = i % data->width;
		prev_y = j + (row * data->width);
		if (row < data->height)
			drawline(data, i, prev_y);
		if (j != 0 && i != 0)
			drawline(data, i, i - 1);
		i++;
	}
}
