/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:43:50 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 21:53:32 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		sf_d_abs(double temp)
{
	return ((temp < 0) ? -temp : temp);
}

int			sf_usage(void)
{
	ft_putendl("USAGE: fractol [name fractal]");
	ft_putendl("       mandelbrot");
	ft_putendl("       julia");
	ft_putendl("       burning");
	ft_putendl("       tricorn");
	ft_putendl("       holes");
	return (0);
}

int			check(char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		return (1);
	else if (!ft_strcmp(str, "julia"))
		return (2);
	else if (!ft_strcmp(str, "burning"))
		return (3);
	else if (!ft_strcmp(str, "tricorn"))
		return (4);
	else if (!ft_strcmp(str, "holes"))
		return (5);
	else
		return (0);
}

int			main(int argc, char **argv)
{
	int		n;
	t_mlx	*mlx;

	if (argc < 2)
		return (sf_usage());
	if (!(n = check(argv[1])))
		return (sf_usage());
	mlx = sf_new_mlx(argv[1], n);
	sf_render(mlx);
	mlx_key_hook(mlx->win_ptr, hook_keydown, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_x, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win_ptr, 6, 1L << 8, hook_mousemove, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
