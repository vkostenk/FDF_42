/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostenk <vkostenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:06:36 by vkostenk          #+#    #+#             */
/*   Updated: 2018/11/30 20:24:49 by vkostenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reader(t_coord_data *data)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(data->name_of_file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		x = ft_count_words(line, ' ');
		y++;
		free(line);
	}
	close(fd);
	data->height = y;
	data->width = x;
	data->total_dots = x * y;
	data->step_x = 500 / data->width;
	data->step_y = 500 / data->height;
}

void		deal_with_coords(int num, t_coord_data *data, int j)
{
	data->cords[j].x = (data->cur_x - data->cur_y +
			data->step_x) * cos(0.523599);
	data->cords[j].y = -(num * data->depth)
		+ (data->cur_x + data->cur_y) * sin(0.523599);
	data->cur_x += data->step_x;
}

void		xuita(t_coord_data *data, int fd, int row)
{
	int		i;
	int		j;
	char	**tab;
	char	*line;

	j = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		while (i < data->width)
		{
			deal_with_coords(ft_atoi(tab[i]), data, j);
			j++;
			i++;
		}
		free(line);
		free(tab);
		row++;
		data->cur_x = 100;
		data->cur_y += (data->step_y);
		i = 0;
	}
}

void		transfer_coords(t_coord_data *data)
{
	int		fd;
	int		row;

	row = 0;
	fd = open(data->name_of_file, O_RDONLY);
	data->cur_x = 100;
	data->cur_y = 100;
	xuita(data, fd, row);
	close(fd);
}
