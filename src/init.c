/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:53:46 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 16:40:11 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	init_sun()
{
	objects[1].mass = SUN_MASS;
	objects[1].size = SUN_MASS / SIZE_MODIFIER;
	objects[1].coords = (t_vector){.x = WINDOW_W / 2, .y = WINDOW_H / 2};
	objects[1].rotation = 0.f;
	objects[1].velocity = (t_vector){.x = 0, .y = 0};
	objects[1].type = sun;
	init_texture("img/sun.png", &(objects[1].tex));
	objects[1].rect = (SDL_Rect){.w = objects[1].size, .h = objects[1].size, 
								.x = WINDOW_W / 2 - objects[1].size / 2,
								.y = WINDOW_H / 2 - objects[1].size / 2};
	objects[1].collision_scalar = 0.3;
}

void	init_planets()
{
	char	planet_img[] = "img/planetx.png";
	int i = 0;
	t_vector	planet_coords[10] = PLANET_COORDS;
	while (i < PLANET_COUNT)
	{
		objects[i+2].mass = SUN_MASS / (i + 2);
		objects[i+2].size = objects[i+2].mass / SIZE_MODIFIER;
		objects[i+2].coords = planet_coords[i];
		objects[i+2].rotation = 0.f;
		objects[i+2].velocity = (t_vector){.x = 0, .y = 0};
		objects[i+2].type = planet;
		planet_img[10] = i + 48;
		init_texture(planet_img, &(objects[i+2].tex));
		objects[i+2].rect = (SDL_Rect){.w = objects[i+2].size, .h = objects[i+2].size, 
								.x = objects[i+2].coords.x - objects[i+2].size / 2,
								.y = objects[i+2].coords.y - objects[i+2].size / 2};
		objects[i+2].collision_scalar = 0.6;
		i++;
	}
}

void	init_player()
{
		objects[0].mass = PLAYER_MASS;
		objects[0].size = objects[0].mass / SIZE_MODIFIER;
		objects[0].coords = PLAYER_START;
		objects[0].rotation = 0.f;
		objects[0].velocity = PLAYER_INITIAL_VELOCITY;
		objects[0].type = player;
		init_texture("img/player.png", &(objects[0].tex));
		objects[0].rect = (SDL_Rect){.w = objects[0].size, .h = objects[0].size, 
								.x = objects[0].coords.x - objects[0].size / 2,
								.y = objects[0].coords.y - objects[0].size / 2};
		objects[0].collision_scalar = 0.5;
}

void	init_asteroids()
{
	int i = 0;
	while (i < INITIAL_ASTEROIDS)
	{
		create_asteroid();
		i++;
	}
	
}

void	init_objects()
{
	ft_bzero(objects, sizeof(t_object) * MAX_OBJECTS);
	init_texture("img/stars.jpeg", &g_stars);
	init_sun();
	init_planets();
	init_player();
	init_asteroids();
}

void	init_SDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Could not Init: %s\n", SDL_GetError());
		exit (1);
	}
	
	/*if (IMG_Init(IMG_INIT_JPG) != 0)
	{
		printf("Could not Init IMG: %s\n", SDL_GetError());
		return (1);
	}*/

	win = SDL_CreateWindow("Asteriod",
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										WINDOW_W, WINDOW_H, 0);
	if (!win)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		exit (1);
	}
	
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("Error creating renderer\n");
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit (1);
	}
}

void	init()
{
	init_SDL();
	init_objects();
}
