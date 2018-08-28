/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:41:07 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 22:25:55 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sf_set_pixel(t_image *img, int x, int y, int color)
{
	if (x < 0 || y < 0 || x > img->i_width || y > img->i_height)
		return ;
	*(int*)(img->ptr + (x + y * img->i_width) * img->bpp) = color;
}

int			sf_set_mouse(t_mouse *m)
{
	m->zoom = 1.5;
	m->mov_x = -1;
	m->mov_y = 0;
	return (1);
}

void		sf_set_mandelbrot(t_mlx *mlx, t_fract *f, int x, int y)
{
	f->pr = (1.5 * ((x - mlx->img->i_width / 2) + mlx->mouse->mov_x))
			/ (0.5 * mlx->mouse->zoom * mlx->img->i_width) + mlx->mouse->mov_x;
	f->pi = ((y - mlx->img->i_height / 2) + mlx->mouse->mov_y)
			/ (0.5 * mlx->mouse->zoom * mlx->img->i_height) + mlx->mouse->mov_y;
	f->new_re = 0;
	f->new_im = 0;
	f->old_re = 0;
	f->old_im = 0;
	f->is_inside = 1;
	f->i = 0;
}

void		sf_set_julia(t_mlx *mlx, t_fract *f, int x, int y)
{
	f->pr = -0.36;
	f->pi = 0.76;
	f->new_re = (1.5 * ((x - mlx->img->i_width / 2) + mlx->mouse->mov_x))
		/ (0.5 * mlx->mouse->zoom * mlx->img->i_width) + mlx->mouse->mov_x;
	f->new_im = ((y - mlx->img->i_height / 2) + mlx->mouse->mov_y)
		/ (0.5 * mlx->mouse->zoom * mlx->img->i_height) + mlx->mouse->mov_y;
	f->old_re = 0.11;
	f->old_im = 0;
	f->is_inside = 0;
	f->i = 0;
}

void		sf_set_burning(t_mlx *mlx, t_fract *f, int x, int y)
{
	f->pr = (1.5 * ((x - mlx->img->i_width / 2) + mlx->mouse->mov_x))
			/ (0.5 * mlx->mouse->zoom * mlx->img->i_width) + mlx->mouse->mov_x;
	f->pi = ((y - mlx->img->i_height / 2) + mlx->mouse->mov_y)
			/ (0.5 * mlx->mouse->zoom * mlx->img->i_height) + mlx->mouse->mov_y;
	f->new_re = 0;
	f->new_im = 0;
	f->old_re = 0;
	f->old_im = 0;
	f->is_inside = 1;
	f->i = 0;
}
