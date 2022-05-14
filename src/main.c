/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:54:07 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/14 14:55:44 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

int	main(void)
{
	t_object objects[MAX_OBJECTS];
	init_objects(objects);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Could not Init: %s\n", SDL_GetError());
		return (1);
	}
	
	/*if (IMG_Init(IMG_INIT_JPG) != 0)
	{
		printf("Could not Init IMG: %s\n", SDL_GetError());
		return (1);
	}*/

	SDL_Window* win = SDL_CreateWindow("Asteriod",
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										WINDOW_W, WINDOW_H, 0);
	if (!win)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("Error creating renderer\n");
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}
	SDL_Surface* surface = IMG_Load("img/stars.jpeg");
	if (!surface)
	{
		printf("Error loading image renderer\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	if (!tex)
	{
		printf("Error loading image renderer\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}
	SDL_FreeSurface(surface);
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, tex, NULL, NULL);
	SDL_RenderPresent(rend);

	int run = 1;
	SDL_Event ev;

	while (run)
	{
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
				case SDL_QUIT:
					run = 0;
					break;
			}
		}
	}

	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
