/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:39:43 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/10 14:16:18 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/** Fnc to initiate the Real and Imaginary parts of the complex number **/

t_oper	complex_init(double r, double i)
{
	t_oper	complex;

	complex.r = r;
	complex.i = i;
	return (complex);
}

/** Initiate the img mlx uses **/

t_img	*img_init(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	img->data_addr = mlx_get_data_addr(img->img, &(img->bpp), \
		&(img->line_size), &(img->endian));
	return (img);
}

/** default value to initiate everything else **/

void	default_init(t_mlx *mlx)
{
	mlx->iter_max = 50;
	mlx->min.r = -2.0;
	mlx->max.r = 2.0;
	mlx->min.i = -2.0;
	mlx->max.i = 2.0;
	mlx->k = complex_init(-0.4, 0.6);
	mlx->press = 0;
	mlx->shift = 1;
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
