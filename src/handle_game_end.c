/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:26:42 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 15:58:33 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	handle_game_end(void)
{
	SDL_Delay(1000*5);
	SDL_Texture *end_screen;
	init_texture(g_victory ? "img/victory.png" : "img/loss.png" ,&end_screen);
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, end_screen, NULL, NULL);
	SDL_RenderPresent(rend);
	SDL_Delay(1000*5);
}
