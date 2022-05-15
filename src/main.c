/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:54:07 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 17:06:21 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

int	main(void)
{
	init();
	tick();
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
