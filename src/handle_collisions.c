/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:33:24 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 15:28:21 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>


void	reset_asteroid(int i)
{
	objects[i].mass = (rand() 
				% (MAX_ASTEROID_MASS + MIN_ASTEROID_MASS + 1)
				+ MIN_ASTEROID_MASS);
	objects[i].size = objects[i].mass / SIZE_MODIFIER;
	set_random_pos(i);
	objects[i].velocity = (t_vector){
				.x = (rand() % (MAX_ASTEROID_VEL + MIN_ASTEROID_VEL + 1)
				+ MIN_ASTEROID_VEL) - MAX_ASTEROID_VEL / 2,
				.y = (rand() 
				% (MAX_ASTEROID_VEL + MIN_ASTEROID_VEL + 1)
				+ MIN_ASTEROID_VEL) - MAX_ASTEROID_VEL / 2};
	objects[i].rect = 
			(SDL_Rect){.w = objects[i].size,
						.h = objects[i].size, 
						.x = objects[i].coords.x
							- objects[i].size / 2,
						.y = objects[i].coords.y
							- objects[i].size / 2};
}

void	hide_object(int i)
{
	objects[i].size = 0;
	objects[i].coords.x = 2 * WINDOW_W;
	SDL_DestroyTexture(objects[i].tex);
}

void	update_size(int i)
{
	objects[i].size = objects[i].mass / SIZE_MODIFIER;
	objects[i].rect.w = objects[i].size;
	objects[i].rect.h = objects[i].size;
}

void	increment_mass(int i, float mass_increment)
{
	objects[i].mass += mass_increment;
	update_size(i);
}

void	reset_player(void)
{
	objects[0].mass = PLAYER_MASS;
	update_size(0);
	objects[0].coords = PLAYER_START;
	objects[0].velocity = PLAYER_INITIAL_VELOCITY;
}

void	collision(int larger, int smaller)
{
	switch (objects[larger].type)
	{
		case player:
			increment_mass(larger, objects[smaller].mass);
			break;
		case asteroid:
			increment_mass(larger, objects[smaller].mass);
			break;
		default:
			break;
	}
	switch (objects[smaller].type)
	{
		case player:
			reset_player();
			break;
		case asteroid:
			reset_asteroid(smaller);
			break;
		case planet:
			hide_object(smaller);
			break;
		case sun:
			hide_object(smaller);
			g_game_end = 1;
			if (bigger == 0)
				g_victory = 1;
			else
				g_victory = 0;
			break;
		default:
			break;
	}
}

void	handle_collisions(void)
{
	int	i;
	int	col_return;

	for (i = 0; i < MAX_OBJECTS; i++)
	{
		if (objects[i].type == planet || objects[i].type == sun ||
			objects[i].size == 0)
			continue;
		col_return = is_colliding(i);
		if (col_return >= 0)
		{
			if (objects[i].size >= objects[col_return].size)
				collision(i, col_return);
			else
				collision(col_return, i);
		}
	}
}
