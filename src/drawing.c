/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:20:32 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 21:46:19 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sf_drawing_one(t_mlx *mlx, t_fract *f, int x, int y)
{
	if (0 <= f->i && f->i < (f->max_iterations / 2))
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f,
									0x000000,
									sf_set_color(&f->color->red,
												&f->color->green,
												&f->color->blue)));
	if (f->i >= (f->max_iterations / 2) && f->i <= f->max_iterations)
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f, sf_set_color(
							&f->color->red,
							&f->color->green,
							&f->color->blue),
									0xFFFFFF));
}

void		sf_drawing_thecond(t_mlx *mlx, t_fract *f, int x, int y)
{
	if (0 <= f->i && f->i < (f->max_iterations / 2))
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f,
									0xFFFFFF,
									sf_set_color(&f->color->red,
												&f->color->green,
												&f->color->blue)));
	if (f->i >= (f->max_iterations / 2) && f->i <= f->max_iterations)
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f, sf_set_color(
							&f->color->red,
							&f->color->green,
							&f->color->blue),
									0xF8F80F));
}

void		sf_drawing_third(t_mlx *mlx, t_fract *f, int x, int y)
{
	if (0 <= f->i && f->i < (f->max_iterations / 2))
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f,
									0x000000,
									sf_set_color(&f->color->red,
												&f->color->green,
												&f->color->blue)));
	if (f->i >= (f->max_iterations / 2) && f->i <= f->max_iterations)
		sf_set_pixel(mlx->img, x, y,
					sf_fractal_color(f, sf_set_color(
							&f->color->red,
							&f->color->green,
							&f->color->blue),
									0xF28227));
}
