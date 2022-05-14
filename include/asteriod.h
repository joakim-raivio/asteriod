/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteriod.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:34:34 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/14 14:55:03 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERIOD_H
# define ASTERIOD_H
# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_surface.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# define WORLD_SIZE 300
# define GRAVITY 0.000000000066741
# define WINDOW_W 1280
# define WINDOW_H 800
# define MAX_OBJECTS 100

typedef enum e_type
{
	player,
	projectile,
	body
}	t_type;

typedef struct s_vector
{
	long long int x;
	long long int y;
}	t_vector;

typedef struct s_object
{
	int			size;
	float		mass;
	t_vector	coords;
	float		rotation;
	t_vector	velocity;
	t_type		type;
}	t_object;

//t_vector	grav_force(t_object first, t_object second);
void	init(SDL_Renderer* rend);
void	init_objects(t_object objects[MAX_OBJECTS]);

#endif
