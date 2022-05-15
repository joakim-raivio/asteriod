/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:32:02 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 15:32:14 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	init_texture(char *path, SDL_Texture **tex)
{
	SDL_Surface *surface = IMG_Load(path);
	if (!surface)
	{
		printf("Error creating surface from %s\n", path);
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(1);
	}
	*tex = SDL_CreateTextureFromSurface(rend, surface);
		if (!*tex)
	{
		printf("Error creating texture from %s\n%s\n", path,SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		exit(1);
	}
	SDL_FreeSurface(surface);
}
