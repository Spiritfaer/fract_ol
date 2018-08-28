/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 22:14:12 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/08 21:28:12 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		*sf_new_image(t_mlx *mlx)
{
	t_image	*new_image;

	new_image = (t_image*)malloc(sizeof(t_image));
	new_image->i_width = mlx->w_width - 200;
	new_image->i_height = mlx->w_height;
	new_image->image = mlx_new_image(mlx->mlx_ptr, new_image->i_width,
													new_image->i_height);
	new_image->ptr = mlx_get_data_addr(new_image->image,
										&new_image->bpp,
										&new_image->size_line,
										&new_image->endian);
	new_image->bpp /= 8;
	return (new_image);
}

t_mlx		*sf_new_mlx(char *name, int n)
{
	t_mlx	*sf_new;

	if (!(sf_new = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	sf_new->mlx_ptr = mlx_init();
	sf_new->win_name = ft_strjoin("FRACTOL - ", name);
	sf_new->w_width = 960;
	sf_new->w_height = 540;
	sf_new->win_ptr = mlx_new_window(sf_new->mlx_ptr, sf_new->w_width,
									sf_new->w_height, sf_new->win_name);
	sf_new->img = sf_new_image(sf_new);
	sf_new->color = 0;
	sf_new->index = n;
	sf_new->tab_mod = 0;
	sf_new->fractal = sf_new_fract();
	sf_new->mouse = sf_new_mouse(sf_new);
	return (sf_new);
}

t_fract		*sf_new_fract(void)
{
	t_fract	*new;

	if (!(new = (t_fract*)malloc(sizeof(t_fract))))
		return (NULL);
	new->new_re = 0;
	new->new_im = 0;
	new->old_re = 0;
	new->old_im = 0;
	new->pr = 0;
	new->pi = 0;
	new->is_inside = 1;
	new->i = 0;
	new->max_iterations = 30;
	new->xx = 0.0;
	new->yy = 0.0;
	new->color = (t_color*)malloc(sizeof(t_color));
	new->color->red = 127;
	new->color->green = 127;
	new->color->blue = 127 + 50;
	return (new);
}

t_mouse		*sf_new_mouse(t_mlx *mlx)
{
	t_mouse	*mouse;

	if (!(mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		return (NULL);
	mouse->x = 0;
	mouse->y = 0;
	mouse->lastx = 0;
	mouse->lasty = 0;
	mouse->isdown = 0;
	sf_set_mouse(mouse);
	mlx->mouse = mouse;
	return (mouse);
}
