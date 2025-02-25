/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:09:31 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/07 20:26:38 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "math.h"
# include "minilibx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define S_WIDTH 1920
# define S_HEIGHT 1080

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
# define C 5

typedef struct s_rayc
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_y;
	int			map_x;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	double		wall_dist;
	int			text_x;
	int			text_y;
	double		hit_x;
	int			wall_start;
	int			wall_end;
	double		per_pix;
	double		tex_y_next;
}				t_rayc;

typedef struct s_textures
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**f;
	char		**c;
	int			check_list[6];

}				t_textures;

typedef struct s_player
{
	double		p_x;
	double		p_y;
	char		p_dir;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	size_t		p_b_x;
	size_t		p_b_y;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		**b_map;
	char		**cpymap;
	int			map_row;
	int			b_col;
	int			b_row;

}				t_map;

typedef struct s_img
{
	void		*img;
	int			bpp;
	int			endian;
	int			size_line;
	int			*addr;

}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*so;
	void		*no;
	void		*we;
	void		*ea;
	void		*img;
	int			*addr;
	int			endian;
	int			bpp;
	int			size_line;
	int			map_size;
	t_img		**te_img;

}				t_mlx;

typedef struct s_keyp
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left_p;
	int			right_p;
	double		move_speed;
	double		dir_speed;

}				t_keyp;

typedef struct s_data
{
	t_textures	textures;
	t_map		cub_map;
	char		*path;
	t_player	player;
	t_mlx		*cub_mlx;
	t_rayc		*rayc;
	t_keyp		key;

}				t_data;

void			error_message(char *str);
void			file_path_control(char *argv);
void			texture_count_check(t_data *data);
char			*find_texture_path(char *clean_str);
void			textures_free(t_data *data);
int				is_xpm_file(t_data *data);

void			map_check(t_data *data);
int				check_right_boundary(t_data *data);
int				check_left_boundary(t_data *data);
int				check_down_boundary(t_data *data);
int				check_above_boundary(t_data *data);
void			go_gnl_last(int fd, char *line);
char			*go_pass_textures(char *line, int fd);
void			map_close_check(t_data *data);
void			player_loc(t_data *data);
int				max_row_lenght(t_data *data);
int				max_col_length(t_data *data);
void			flood_fill_check(t_data *data);
void			character_check(t_data *data);
void			b_map_check(t_data *data);

void			free_data(t_data *data);
void			fill_map_free(t_data *data);
void			map_free(t_data *data, char *line, int fd);
void			double_str_free(char **str);
char			**find_color_num(t_data *data, char *clean_str, int type);
void			player_check(t_data *data);
void			find_dir(t_data *data);
void			game_start(t_data *data);
int				key_press(int keycode, t_data *data);
int				close_window(t_data *data);
void			image_init(t_data *data);
void			free_image(t_mlx *cub_mlx);
int				image_loop(t_data *data);
void			raycasting(t_data *data);
void			set_pixel(t_data *data, int line_h, int side);
void			draw_textured_column(t_data *data, int side, int col);
int				key_release(int keycode, t_data *data);
void			call_move(t_data *data);
void			turn_left(t_data *data);
void			turn_right(t_data *data);
void			free_texture_check(t_data *data, char *str, char *clean_str,
					int fd);
int				texture_error(t_data *data, char *clean_str, char *str, int fd);
int				set_texture(t_data *data, char *clean_str);
void			getter_texture(t_data *data, char *clean_str, int index,
					char **texture);
int				is_two_comma(char *clean_str);
int				is_invalid_character(char **int_str);
int				comma_in_fill(char **int_str);
void			check_player_boundary(t_data *data);
void			free_xpm_loop(t_data *data);

#endif