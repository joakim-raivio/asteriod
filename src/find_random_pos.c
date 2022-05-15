/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_random_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:25:30 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 16:10:18 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	set_random_pos(int i)
{
	int iterations;

	iterations = 0;
	while (iterations < 1000)
	{
		objects[i].coords.x = rand() % (WINDOW_W - objects[i].size + 1) + objects[i].size / 2;
		objects[i].coords.y = rand() % (WINDOW_H - objects[i].size + 1) + objects[i].size / 2;
		if (is_colliding(i) == -1)
			return;
		iterations++;
	}
}
