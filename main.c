/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:59:55 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 20:17:35 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_data(char *s, t_coord_data *data)
{
	data->name_of_file = s;
	data->cords = (t_coord *)malloc(sizeof(t_coord) * data->total_dots);
	data->change_x = 500;
	data->change_y = 100;
	data->depth = 5;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "lol");
}

int			main(int argc, char **argv)
{
	t_coord_data	*data;
	int				fd;

	data = malloc(sizeof(t_coord_data));
	if (argc < 2 || argc > 2)
	{
		write(1, "Usage: ./fdf [map]\n", 19);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY) <= 0))
	{
		write(1, "Yo, bro, check file name\n", 25);
		return (-1);
	}
	init_data(argv[1], data);
	reader(data);
	transfer_coords(data);
	conect_dots(data);
	mlx_hook(data->win_ptr, 2, 5, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free(data->cords);
	free(data);
	return (0);
}
