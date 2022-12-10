/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:23:34 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/10 22:50:38 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/** I am using lerp algorithm where start and end value don't change during
 *  interpolation. The interpolation value changes which is a percentage 
 *  ranging from 0.0 to 1.0 --> distance betn two given points.
 *  An extra check is there for the coeff value range.
 **/

// double	lerp(double start, double end, double inter_coeff)
// {
// 	if (inter_coeff <= 0.0)
// 		return (start);
// 	if (inter_coeff >= 1.0)
// 		return (end);
// 	return ((1 - inter_coeff) * start + inter_coeff * end);
// }

double	lerp(double start, double end, double inter_coeff)
{
	return (start + ((end - start) * inter_coeff));
}

int	ctrl_mouse(int key, int x, int y, t_mlx *mlx)
{
	t_oper	mouse;
	double	zoom;

	if (key == 1)
		mlx->press = 1;
	mouse.r = (mlx->min.r + x * ((mlx->max.r - mlx->min.r)
				/ (WIDTH)));
	mouse.i = (mlx->max.i - y * ((mlx->max.i - mlx->min.i)
				/ (HEIGHT)));
	if (key == 5)
		zoom = 1.20;
	else if (key == 4)
		zoom = 0.80;
	else
		zoom = 1.0;
	mlx->min.r = lerp(mouse.r, mlx->min.r, zoom);
	mlx->min.i = lerp(mouse.i, mlx->min.i, zoom);
	mlx->max.r = lerp(mouse.r, mlx->max.r, zoom);
	mlx->max.i = lerp(mouse.i, mlx->max.i, zoom);
	render_fractal(mlx);
	return (0);
}

/** this two functions are specifically for julia set
 *   one is key press and the other is changing iteration **/

int	julia_key_press(int key, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (key == 1)
		mlx->press = 0;
	return (0);
}

int	change_julia(int x, int y, t_mlx *mlx)
{
	if (mlx->press == 1)
	{
		mlx->k = complex_init(4 * ((double)x / WIDTH - 0.5), \
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		render_fractal(mlx);
	}
	return (0);
}
