/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:37:50 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 21:43:04 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			sf_set_color(int *red, int *green, int *blue)
{
	int		color;

	color = 0;
	if (*red > 255)
		*red -= 255;
	if (*green > 255)
		*green -= 255;
	if (*blue > 255)
		*blue -= 255;
	color |= (0 << 24) & 0xFF000000;
	color |= (*red << 16) & 0x00FF0000;
	color |= (*green << 8) & 0x0000FF00;
	color |= *blue & 0x000000FF;
	return (color);
}

int			set_red(int color_1, int color_2, double l, int iter)
{
	int		new_red;

	if ((int)l < iter)
		return (color_2);
	color_1 = ((color_1 >> 16) & 0xFF);
	color_2 = ((color_2 >> 16) & 0xFF);
	new_red = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_red >= 0xFF && new_red < 0xFFF)
		new_red = 0xFF;
	if (new_red > 0xFFF)
		new_red = 0;
	return (((new_red << 16) & 0xFF0000));
}

int			set_green(int color_1, int color_2, double l, int iter)
{
	int		new_green;

	if ((int)l < iter)
		return (color_2);
	color_1 = ((color_1 >> 8) & 0xFF);
	color_2 = ((color_2 >> 8) & 0xFF);
	new_green = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_green >= 0xFF && new_green < 0xFFF)
		new_green = 0xFF;
	if (new_green > 0xFFF)
		new_green = 0;
	return (((new_green << 8) & 0x00FF00));
}

int			set_blue(int color_1, int color_2, double l, int iter)
{
	int new_blue;

	if ((int)l < iter)
		return (color_2);
	color_1 &= 0xFF;
	color_2 &= 0xFF;
	new_blue = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_blue >= 0xFF && new_blue < 0xFFF)
		new_blue = 0xFF;
	if (new_blue > 0xFFF)
		new_blue = 0;
	return ((new_blue & 0xFF));
}

int			sf_fractal_color(t_fract *f, int color_1, int color_2)
{
	int		new_color;
	double	length;
	int		iter;

	length = f->max_iterations / 2 - 0.5;
	iter = (f->i > (int)length) ? f->i - (int)length : f->i;
	if (length < 1.0)
		return (color_2);
	new_color = 0;
	new_color |= set_red(color_1, color_2, length, iter);
	new_color |= set_green(color_1, color_2, length, iter);
	new_color |= set_blue(color_1, color_2, length, iter);
	return (new_color);
}
