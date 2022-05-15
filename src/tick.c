/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:32:54 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 15:28:45 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	tick(void)
{
	int			run = 1;
	SDL_Event	ev;
	t_input		input;

	input = (t_input){.up = 0, .left = 0, .right = 0, .down = 0};
	g_game_end = 0;
	while (run)
	{
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					run = 0;
					break;
				case SDL_KEYDOWN:
					switch (ev.key.keysym.scancode)
					{
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							input.up = 1;
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							input.left = 1;
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							input.right = 1;
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							input.down = 1;
							break;
						default:
							break;
					}
					break;
				case SDL_KEYUP:
					switch (ev.key.keysym.scancode)
					{
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							input.up = 0;
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							input.left = 0;
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							input.right = 0;
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							input.down = 0;
							break;
						default:
							break;
					}
				default:
					break;
			}
		}
		handle_input(input);
		handle_gravity();
		move_objects();
		handle_collisions();
		render();
		SDL_Delay(1000/FRAMERATE);
		if (g_game_end)
		{
			handle_game_end();
			break;
		}
	}
}
