/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:26:56 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 14:29:37 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	move_objects(void)
{
	int i;

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		if (objects[i].type == planet || objects[i].type == sun)
			continue;
		objects[i].coords.x += objects[i].velocity.x / 60 * VELOCITY_SCALAR;
		objects[i].coords.y += objects[i].velocity.y / 60 * VELOCITY_SCALAR;
		if (objects[i].coords.x < 0)
			objects[i].coords.x += WINDOW_W;
		else if (objects[i].coords.x > WINDOW_W)
			objects[i].coords.x -= WINDOW_W;
		if (objects[i].coords.y < 0)
			objects[i].coords.y += WINDOW_H;
		else if (objects[i].coords.y > WINDOW_H)
			objects[i].coords.y -= WINDOW_H;
		objects[i].rect.x = objects[i].coords.x - objects[i].size / 2;
		objects[i].rect.y = objects[i].coords.y - objects[i].size / 2;
	}
}
