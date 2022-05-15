/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:19:24 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 00:25:33 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	render(void)
{
	int i;

	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, g_stars, NULL, NULL);
	for (i = 0; i < MAX_OBJECTS; i++)
	{
		if (objects[i].tex)
		{
			SDL_RenderCopy(rend, objects[i].tex, NULL, &(objects[i].rect));
		}
	}
	//SDL_SetRenderDrawColor(rend, 255, 255, 255, SDL_ALPHA_OPAQUE);
	//SDL_RenderDrawLine(rend, objects[0].coords.x, objects[0].coords.y,
	//objects[0].coords.x + (int)g_cur_grav.x, objects[0].coords.y + (int)g_cur_grav.y);
	SDL_RenderPresent(rend);
}
