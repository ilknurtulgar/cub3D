/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:15:41 by zayaz             #+#    #+#             */
/*   Updated: 2025/02/05 19:50:06 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3D.h"

void	find_dir2(t_data *data)
{
	if (data->player.p_dir == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else if (data->player.p_dir == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}

void	find_dir(t_data *data)
{
	data->key.move_speed = 0.032;
	data->key.dir_speed = 0.03;
	if (data->player.p_dir == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (data->player.p_dir == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else
		find_dir2(data);
}

void	game_start(t_data *data)
{
	data->cub_mlx = malloc(sizeof(t_mlx));
	data->cub_mlx->mlx = mlx_init();
	data->cub_mlx->window = mlx_new_window(data->cub_mlx->mlx, S_WIDTH,
			S_HEIGHT, "cub3D");
	image_init(data);
	mlx_loop_hook(data->cub_mlx->mlx, image_loop, data);
	mlx_hook(data->cub_mlx->window, 2, 1L << 0, key_press, data);
	mlx_hook(data->cub_mlx->window, 3, 1L << 1, key_release, data);
	mlx_hook(data->cub_mlx->window, 17, 0, close_window, data);
	mlx_loop(data->cub_mlx->mlx);
}
