/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:45:18 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/15 15:04:22 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

void	add_player_vel(t_input	input)
{
	t_vector	total;

	total.x = 0 + (input.right * PLAYER_ACCELERATION)
				+ (input.left * PLAYER_ACCELERATION * -1);
	total.y = 0 + (input.down * PLAYER_ACCELERATION)
				+ (input.up * PLAYER_ACCELERATION * -1);
	objects[0].velocity.x += total.x;
	objects[0].velocity.y += total.y;
}

void	handle_input(t_input input)
{
	add_player_vel(input);
}
