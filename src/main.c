/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:43:36 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/12 01:50:54 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include<stdio.h>

/** Function to draw/render fractal on screen **/

void	render_fractal(t_mlx *mlx)
{
	int		x;
	int		y;
	t_oper	scale;

	scale = complex_init((mlx->max.r - mlx->min.r) \
		/ (WIDTH), (mlx->max.i - mlx->min.i) / (HEIGHT));
	y = 0;
	while (y < HEIGHT)
	{
		mlx->c.i = mlx->max.i - y * scale.i;
		x = 0;
		while (x < WIDTH)
		{
			mlx->c.r = mlx->min.r + x * scale.r;
			mlx->eqn(mlx);
			recode_mlx_pixel_put(mlx, x, y, color_init(mlx));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

/** Help me brooooo , help me **/

void	help_options(void)
{
	ft_putendl_fd("**************************\n", 1);
	ft_putendl_fd("How to use: ./fractol <no>", 1);
	ft_putendl_fd("Available Fractols:", 1);
	ft_putendl_fd("mandelbrot -- 1", 1);
	ft_putendl_fd("julia -- 2", 1);
	ft_putendl_fd("burningship-- 3", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Mouse:", 1);
	ft_putendl_fd("For Zoom: scrollWheel", 1);
	ft_putendl_fd("Move it, move it and julia changes", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("Keys:", 1);
	ft_putendl_fd("WASD keys to move", 1);
	ft_putendl_fd("Q and E to increase or decrease iterations", 1);
	ft_putendl_fd("C to shift colors", 1);
	ft_putendl_fd("SPACE to reset braaah", 1);
	ft_putendl_fd("Don't dare to do ESC", 1);
	ft_putendl_fd("**************************\n", 1);
}

/**
 * @brief Setting up window
 *         We init everything, create new win,image
 *         and the hooks for mouse and keyboard
 *         Julia set is bit different functionality
 *         so used diff hooks for that. then we use
 *         render fractal function to draw and mlx_loop
 *         to keep it going until user quits
 */
void	gui_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, \
		"FrAct-ol");
	mlx->img = img_init(mlx);
	default_init(mlx);
	mlx_hook(mlx->win, 2, 0, keymap, mlx);
	mlx_hook(mlx->win, 4, 0, ctrl_mouse, mlx);
	if (mlx->eqn == &mandelbrot)
		mlx_hook(mlx->win, 17, 0, close_window, mlx);
	if (mlx->eqn == &julia)
	{
		mlx_hook(mlx->win, 5, 0, julia_key_press, mlx);
		mlx_hook(mlx->win, 2, 0, keymap, mlx);
		mlx_hook(mlx->win, 6, 0, change_julia, mlx);
		mlx_hook(mlx->win, 17, 0, close_window, mlx);
		ft_putendl_fd("Julia is overcooked", 1);
	}
	render_fractal(mlx);
	mlx_loop(mlx->mlx);
}

/** This is for parsing with ft_strncmp and using ft_strlen to 
 *  compare the user typed actual names. If they match, it loads
 *  the fractal
 **/

void	arg_check(char *arg)
{	
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!(ft_strncmp(arg, "1", 1)))
	{
		mlx->eqn = &mandelbrot;
		gui_init(mlx);
	}	
	else if (!(ft_strncmp(arg, "2", 1)))
	{
		mlx->eqn = &julia;
		gui_init(mlx);
	}
	else if (!(ft_strncmp(arg, "3", 1)))
	{
		mlx->eqn = &burning_ship;
		gui_init(mlx);
	}
	free (mlx);
	help_options();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		arg_check(argv[1]);
	else
		help_options();
	return (0);
}
