/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:00:16 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 19:49:30 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_depth_minus(t_coord_data *data)
{
	data->depth = data->depth - 1;
	if (data->depth < -15)
		data->depth = -15;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	transfer_coords(data);
	conect_dots(data);
}

void		change_depth_plus(t_coord_data *data)
{
	data->depth = data->depth + 1;
	if (data->depth > 20)
		data->depth = 20;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	transfer_coords(data);
	conect_dots(data);
}
