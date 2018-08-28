/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:42:13 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/08 21:27:08 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sf_clear(t_mlx *mlx)
{
	ft_bzero(mlx->img->ptr, ((size_t)mlx->img->i_width
							* (size_t)mlx->img->i_height
							* (size_t)mlx->img->bpp));
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
}

void		sf_render(t_mlx *mlx)
{
	if (mlx->index == 1)
		sf_draw(mlx, sf_set_mandelbrot, sf_mandelbrot, sf_drawing_one);
	else if (mlx->index == 2)
		sf_draw(mlx, sf_set_julia, sf_julia, sf_drawing_thecond);
	else if (mlx->index == 3)
		sf_draw(mlx, sf_set_burning, sf_burning, sf_drawing_third);
	else if (mlx->index == 4)
		sf_draw(mlx, sf_set_mandelbrot, sf_tricorn, sf_drawing_thecond);
	else if (mlx->index == 5)
		sf_draw(mlx, sf_set_julia, sf_holes, sf_drawing_one);
}

void		sf_draw(t_mlx *mlx,
					void (*set_fractal)(t_mlx*, t_fract*, int, int),
					void (*fractol)(t_fract*),
					void (*drawing)(t_mlx*, t_fract*, int, int))
{
	int			x;
	int			y;
	t_fract		*f;

	f = mlx->fractal;
	sf_clear(mlx);
	y = 0;
	while (y < mlx->img->i_height)
	{
		x = 0;
		while (x < mlx->img->i_width)
		{
			set_fractal(mlx, f, x, y);
			fractol(f);
			drawing(mlx, f, x, y);
			x++;
		}
		y++;
	}
	sf_draw_interface(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img->image, 200, 0);
}
