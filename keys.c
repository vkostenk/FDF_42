/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:00:10 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 19:48:12 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_x_right(t_coord_data *data)
{
	data->change_x = data->change_x + 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	conect_dots(data);
}

void		move_x_left(t_coord_data *data)
{
	data->change_x = data->change_x - 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	conect_dots(data);
}

void		move_y_up(t_coord_data *data)
{
	data->change_y = data->change_y - 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	conect_dots(data);
}

void		move_y_down(t_coord_data *data)
{
	data->change_y = data->change_y + 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	conect_dots(data);
}

int			deal_key(int key, t_coord_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 124)
		move_x_right(data);
	else if (key == 123)
		move_x_left(data);
	else if (key == 126)
		move_y_up(data);
	else if (key == 125)
		move_y_down(data);
	else if (key == 12)
		change_depth_minus(data);
	else if (key == 13)
		change_depth_plus(data);
	return (0);
}
