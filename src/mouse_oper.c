/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:23:34 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/08 23:58:37 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/** I am using lerp algorithm where start and end value don't change during
 *  interpolation. The interpolation value changes which is a percentage 
 *  ranging from 0.0 to 1.0 --> distance betn two given points.
 *  An extra check is there for the coeff value range.
 **/

float	lerp(float start, float end, float inter_coeff)
{
	if (inter_coeff <= 0.0)
		return (start);
	if (inter_coeff >= 1.0)
		return (end);
	return ((1 - inter_coeff) * start + inter_coeff * end);
}

int	ctrl_mouse(int key, int x, int y, t_mlx *mlx)
{
	t_oper	mouse;
	float	zoom;

	if (key == KEY_S)
		mlx->press = KEY_S;
	mouse.r = (mlx->min.r + x * ((mlx->max.r - mlx->min.r)
				/ (WIDTH)));
	mouse.i = (mlx->max.i - y * ((mlx->max.i - mlx->min.i)
				/ (HEIGHT)));
	if (key == KEY_G)
		zoom = 1.20;
	else if (key == KEY_H)
		zoom = 0.80;
	else
		zoom = 1.0;
	mlx->min.r = lerp(mouse.r, mlx->min.r, zoom);
	mlx->min.i = lerp(mouse.i, mlx->min.i, zoom);
	mlx->max.r = lerp(mouse.r, mlx->max.r, zoom);
	mlx->min.i = lerp(mouse.i, mlx->min.r, zoom);
	render_fractal(mlx);
	return (0);
}

/** this two functions are specifically for julia set
 *   one is key press and the other is changing iteration **/

int	julia_key_press(int key, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (key == KEY_S)
		mlx->press = KEY_A;
	return (0);
}

int	change_julia(int x, int y, t_mlx *mlx)
{
	if (mlx->press == KEY_S)
	{
		mlx->k = complex_init(4 * ((float)x / WIDTH - 0.5), \
			4 * ((float)(HEIGHT - y) / HEIGHT - 0.5));
		render_fractal(mlx);
	}
	return (0);
}
