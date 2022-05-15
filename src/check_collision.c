/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:52:24 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 14:35:45 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>
#include <math.h>

int	check_collision(t_object first, t_object second)
{
	return (get_distance(first.coords, second.coords)
		   < (first.size * first.collision_scalar >
			second.size * second.collision_scalar ? 
			first.size * first.collision_scalar : 
			second.size * second.collision_scalar));
}

int	is_colliding(int object_i)
{
	int i;

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		if (i == object_i)
			continue;
		if (objects[i].size == 0)
			continue;
		if (check_collision(objects[object_i], objects[i]))
			return (i);
	}
	return (-1);
}
