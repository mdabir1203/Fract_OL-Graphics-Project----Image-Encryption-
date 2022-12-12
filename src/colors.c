/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:30:35 by mabbas            #+#    #+#             */
/*   Updated: 2022/12/12 02:22:17 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/** Used bitshifting to interpolate betn diff shades of red, green and blue 
 *  and transparency. By using this way it helps us interpolate
 *  the trgb values individually
 **/
int	trgb_gen(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/** Recoding it as its more faster than the original one
 *  because it uses its separate struct and its easy 
 *  to acces.. Putting the pixel not by bytes but by line by line.  **/

void	recode_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dest;

	dest = mlx->img->data_addr + (y * mlx->img->line_size)
		+ x * (mlx->img->bpp / 8);
	*(unsigned int *)dest = color;
}

/** Color pallete shifting function. Here (1 - t) comes from the Brezier curve
 *  Also 9, 15 , 8.5 are values coming  **/

int	color_init(t_mlx *mlx)
{
	double	t;
	int		color[4];

	t = (double)mlx->iter / (double)mlx->iter_max;
	color[0] = 0;
	if (mlx->shift == 1)
	{
		color[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(14 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 225);
	}
	if (mlx->shift == 2)
	{
		color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(13 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(7 * pow((1 - t), 3) * t * 225);
	}
	if (mlx->shift == 3)
	{
		color[3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(8.5 * pow((1 - t), 3) * t * 225);
	}
	return (trgb_gen(color[0], color[1], color[2], color[3]));
}

// int	color_special(t_mlx *mlx)
// {
// 	int		color[4];
// 	double	x;

// 	color[0] = 0;
// 	x = ((double)mlx->iter) / ((double)(mlx->iter_max));
// 	if (mlx->shift == 4)
// 	{
// 		color[1] = (int)(sin(9) * (1 - x) * pow(x, 3) * 0);
// 		color[2] = (int)(cos(15) * pow((1 - x), 2) * pow(x, 2) * 255);
// 		color[3] = (int)(sin(8.5) * pow((1 - x), 3) * x * 0);
// 	}
// 	return (trgb_gen(color[0], color[1], color[2], color[3]));
/** Experimental Color conversions **/
//		color[1] = (int)(sin(9) * (1 - x) * pow(x, 3) * 0);
// 		color[2] = (int)(cos(15) * pow((1 - x), 2) * pow(x, 2) * 255);
// 		color[3] = (int)(sin(8.5) * pow((1 - x), 3) * x * 0);
		// color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		// color[1] = (int)(13 * pow((1 - t), 2) * pow(t, 2) * 255);
		// color[3] = (int)(7 * pow((1 - t), 3) * t * 225);
