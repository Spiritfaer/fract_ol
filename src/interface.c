/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 22:12:26 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 22:23:32 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		sf_draw_rgb(t_mlx *mlx)
{
	char	*red;
	char	*green;
	char	*blue;

	red = ft_itoa(mlx->fractal->color->red);
	green = ft_itoa(mlx->fractal->color->green);
	blue = ft_itoa(mlx->fractal->color->blue);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 300, 0xF0F000, "RED");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 300 + 50, 0xF0F000, "GREEN");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 300 + 100, 0xF0F000, "BLUE");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 320, 0xFF0F0F, red);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 320 + 50, 0x0FFF0F, green);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 320 + 100, 0x0F0FFF, blue);
	free(red);
	free(green);
	free(blue);
}

void		sf_draw_interface(t_mlx *mlx)
{
	char	*zoom;
	char	*max;

	zoom = ft_strnew((size_t)32);
	sprintf(zoom, "%zu", (size_t)(mlx->mouse->zoom + 0.5));
	max = ft_itoa((int)(mlx->fractal->max_iterations + 0.5));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 20, 0xF0F000, "ZOOM");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					20, 20 + 50, 0xF0F000, "MAX ITERATIONS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					20, 20 + 100, 0xF0F000, "MOUSE STATUS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 40, 0xFFFFFF, zoom);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 40 + 50, 0xFFFFFF, max);
	if ((mlx->tab_mod))
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
						20, 40 + 100, 0xFF0F0F, "WORK");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
						20, 40 + 100, 0x0F0FFF, "FREEZE");
	free(zoom);
	free(max);
	sf_draw_rgb(mlx);
}
