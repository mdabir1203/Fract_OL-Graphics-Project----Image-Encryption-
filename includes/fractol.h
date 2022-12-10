/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:12:22 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/08 14:17:25 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "./keys.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"

/** Defining the parameters of the window **/

# define WIDTH 800
# define HEIGHT 600

#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3

/** 
 Struct for real and imaginary numbers **/
typedef struct s_oper
{
	double	r;
	double	i;
}		t_oper;

/** Struct to draw images **/

typedef struct s_img
{
	void	*img;
	char	*data_addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

/** Struct to calculate fractals **/

typedef struct s_mlx
{
	t_img			*img;
	void			*mlx;
	void			*win;
	int				iter;
	int				iter_max;
	int				press;
	int				shift;
	t_oper			max;
	t_oper			min;
	t_oper			c;
	t_oper			k;
	void			(*eqn)(struct s_mlx *);

}		t_mlx;

t_oper		complex_init(double r, double i);
t_img		*img_init(t_mlx *mlx);

void		default_init(t_mlx *mlx);
int			color_init(t_mlx *mlx);

int			trgb_gen(int t, int r, int g, int b);
void		recode_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
double		lerp(double start, double end, double inter_coeff);

int			ctrl_mouse(int key, int x, int y, t_mlx *mlx);
int			keymap(int key, t_mlx *mlx);

void		render_fractal(t_mlx *mlx);
void		mandelbrot(t_mlx *mlx);
void		julia(t_mlx *mlx);
void		burning_ship(t_mlx *mlx);

void		gui_init(t_mlx *mlx);

void		arg_check(char *arg);
void		help_options(void);

int			change_julia(int x, int y, t_mlx *mlx);
int			julia_key_press(int key, int x, int y, t_mlx *mlx);

void		move_w_key(int key, t_mlx *mlx);
void		shift_color(t_mlx *mlx);

int			close_window(t_mlx *mlx);

#endif
