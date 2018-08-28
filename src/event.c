/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:22:00 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/08 21:26:58 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_x(void)
{
	exit(0);
}

int			hook_keydown(int key, t_mlx *mlx)
{
	if (key == 15)
		mlx->fractal->color->red += 5;
	if (key == 5)
		mlx->fractal->color->green += 5;
	if (key == 11)
		mlx->fractal->color->blue += 5;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 49)
		sf_set_mouse(mlx->mouse);
	if (key == 116)
		mlx->fractal->max_iterations = (mlx->fractal->max_iterations < 200.0)
			? mlx->fractal->max_iterations += 5.0 : 200.0;
	if (key == 121)
		mlx->fractal->max_iterations = (mlx->fractal->max_iterations > 20.0)
			? mlx->fractal->max_iterations -= 5.0 : 20.0;
	if (key == 48)
		mlx->tab_mod = (mlx->tab_mod == 1) ? 0 : 1;
	sf_render(mlx);
	return (0);
}

int			hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	if (button == 5)
		mlx->mouse->zoom += mlx->mouse->zoom * 0.3;
	else if (button == 4)
		mlx->mouse->zoom -= mlx->mouse->zoom * 0.3;
	sf_render(mlx);
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int			hook_mousemove(int x, int y, t_mlx *mlx)
{
	double		step_x;
	double		step_y;

	if (mlx->tab_mod)
	{
		step_x = (x - mlx->mouse->lastx) / 20000.f;
		step_y = (y - mlx->mouse->lasty) / 20000.f;
		mlx->fractal->xx -= step_x / mlx->mouse->zoom;
		mlx->fractal->yy -= step_y / mlx->mouse->zoom;
		sf_render(mlx);
		return (0);
	}
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1))
	{
		step_x = (x - mlx->mouse->lastx) / 200.f;
		step_y = (y - mlx->mouse->lasty) / 200.f;
		mlx->mouse->mov_x -= step_x / mlx->mouse->zoom;
		mlx->mouse->mov_y -= step_y / mlx->mouse->zoom;
	}
	sf_render(mlx);
	return (0);
}
