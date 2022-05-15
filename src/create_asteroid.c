/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_asteroid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:16:46 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 16:23:27 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	create_asteroid(void)
{
	int i = 2 + PLANET_COUNT;
	while (i < MAX_OBJECTS)
	{
		if (objects[i].size == 0)
			break;
		i++;
	}
	if (i == MAX_OBJECTS)
	{
		return;
	}
	objects[i].mass = (rand() 
				% (MAX_ASTEROID_MASS + MIN_ASTEROID_MASS + 1)
				+ MIN_ASTEROID_MASS);
	objects[i].size = objects[i].mass / SIZE_MODIFIER;
	set_random_pos(i);
	objects[i].rotation = 0.f;
	objects[i].velocity = (t_vector){
				.x = (rand() % (MAX_ASTEROID_VEL + MIN_ASTEROID_VEL + 1)
				+ MIN_ASTEROID_VEL) - MAX_ASTEROID_VEL / 2,
				.y = (rand() 
				% (MAX_ASTEROID_VEL + MIN_ASTEROID_VEL + 1)
				+ MIN_ASTEROID_VEL) - MAX_ASTEROID_VEL / 2};
	objects[i].type = asteroid;
	init_texture("img/asteroid0.png", &(objects[i].tex));
	objects[i].rect = 
			(SDL_Rect){.w = objects[i].size,
						.h = objects[i].size, 
						.x = objects[i].coords.x
							- objects[i].size / 2,
						.y = objects[i].coords.y
							- objects[i].size / 2};
	objects[i].collision_scalar = 0.8;
}
