/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:58:45 by alakhdar          #+#    #+#             */
/*   Updated: 2022/02/22 14:55:06 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

//Convertit un plan plat en vue iso en fonction de l'angle alpha donné
void	isometry(float *x, float *y, int z, float alpha)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(alpha);
	*y = -z + (previous_x + previous_y) * sin(alpha);
}
