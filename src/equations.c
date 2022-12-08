/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:35:20 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/09 00:12:32 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief  Finding the no of iterations for mandlebrot

 */
void	mandelbrot(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2) + pow(z.i, 2) <= 4 && mlx->iter < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2) - pow(z.i, 2) + mlx->c.r, \
			2 * z.r * z.i + mlx->c.i);
		mlx->iter++;
	}
}

void	julia(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4
		&& mlx->iter++ < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2.0) - pow(z.i, 2.0) + mlx->k.r, \
		2.0 * z.r * z.i + mlx->k.i);
		mlx->iter++;
	}
}

void	burning_ship(t_mlx *mlx)
{
	t_oper	z;

	z = complex_init(mlx->c.r, mlx->c.i);
	mlx->iter = 0;
	while (pow(z.r, 2.0) + pow(z.i, 2.0) <= 4 && \
				mlx->iter++ < mlx->iter_max)
	{
		z = complex_init(pow(z.r, 2.0) - pow(z.i, 2.0) + \
			(mlx->c.r), -2.0 * labs(z.r * z.i) + mlx->c.i);
	}
}
