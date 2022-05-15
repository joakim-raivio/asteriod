/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteriod.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:34:34 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 16:19:08 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTERIOD_H
# define ASTERIOD_H
# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_mixer.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# define WORLD_SIZE 300
# define GRAVITY_SCALAR 1000.f
# define GRAVITY_EXPONENT 1.5
# define WINDOW_W 1920
# define WINDOW_H 1080
# define MAX_OBJECTS 100
# define SUN_MASS 1000
# define PLANET_COUNT 3
# define PLANET_COORDS {{.x = 250, .y = 220}, {.x = 1100, .y = 210}, {.x = 1400, .y = 800}}
# define SIZE_MODIFIER 4
# define PLAYER_START (t_vector){.x = 1800, .y = 900}
# define PLAYER_INITIAL_VELOCITY (t_vector){.x = 0, .y = 300}
# define PLAYER_MASS 50
# define INITIAL_ASTEROIDS 10
# define MIN_ASTEROID_MASS 10
# define MAX_ASTEROID_MASS 100
# define MIN_ASTEROID_VEL 100
# define MAX_ASTEROID_VEL 500
# define MAX_SPEED 2000
# define FRAMERATE 60
# define VELOCITY_SCALAR 0.3
# define PLAYER_ACCELERATION 10


// Typedefs
typedef enum e_type
{
	player,
	projectile,
	asteroid,
	planet,
	sun
}	t_type;

typedef struct s_vector
{
	double x;
	double y;
}	t_vector;

typedef struct s_object
{
	int				size;
	float			mass;
	t_vector		coords;
	float			rotation;
	t_vector		velocity;
	t_type			type;
	SDL_Texture		*tex;
	SDL_Rect		rect;
	double			collision_scalar;
}	t_object;

typedef struct s_input
{
	int	up;
	int	left;
	int	right;
	int	down;
}	t_input;

// Global variables
SDL_Renderer	*rend;
SDL_Window		*win;
SDL_Texture		*g_stars;
t_object		objects[MAX_OBJECTS];
int				g_game_end;
int				g_victory;
//t_vector		g_cur_grav;

// Functions
//t_vector	grav_force(t_object first, t_object second);
void	init(void);
void	render(void);
void	tick(void);
void	move_objects(void);
int		check_collision(t_object first, t_object second);
void	set_random_pos(int i);
int		is_colliding(int object_i);
void	init_texture(char *path, SDL_Texture **tex);
void	create_asteroid(void);
double	get_distance(t_vector first, t_vector second);
void	handle_gravity(void);
void	move_objects(void);
void	handle_collisions(void);
void	handle_input(t_input input);
void	init_texture(char *path, SDL_Texture **tex);
void	handle_game_end(void);

#endif
