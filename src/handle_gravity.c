/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_gravity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:21:25 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 00:57:01 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>
#include <math.h>

t_vector	get_total_grav(int object_i)
{
	t_vector total = {.x = 0, .y = 0};
	double	force;
	double	angle;
	double	distance;
	t_vector	temp;
	int i;
	for (i = 1; i <= PLANET_COUNT + 1; i++)
	{
		distance = get_distance(objects[object_i].coords, objects[i].coords);
		force = GRAVITY_SCALAR * (objects[i].mass / pow(distance, GRAVITY_EXPONENT));
		temp.x = (objects[i].coords.x - objects[object_i].coords.x) / distance;
		temp.y = (objects[i].coords.y - objects[object_i].coords.y) / distance;
		angle = atan2(temp.y, temp.x);
		total.x += force * cos(angle);
		total.y += force * sin(angle);
	}
	printf("Force: %lf\nAngle: %lf\nDistance: %lf\nTotal: X: %lf - Y: %lf\n", force, angle, distance, total.x, total.y);
	return (total);
}

void	handle_gravity(void)
{
	int			i;
	t_vector	cur;
	double		total_vel;
	double		vel_scalar;

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		if (objects[i].type == sun || objects[i].type == planet
			   	|| objects[i].size == 0)
			continue;
		cur = get_total_grav(i);
		objects[i].velocity.x += cur.x / 60;
		objects[i].velocity.y += cur.y / 60;
		total_vel = get_distance(objects[i].velocity, (t_vector){.x = 0, .y = 0});
		if (total_vel > MAX_SPEED)
		{
			vel_scalar = MAX_SPEED / total_vel;
			objects[i].velocity.x *= vel_scalar;
			objects[i].velocity.y *= vel_scalar;
		}
		//g_cur_grav.x = cur.x;
		//g_cur_grav.y = cur.y;
	}
}
