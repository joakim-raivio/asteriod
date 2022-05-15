/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraivio <jraivio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:26:19 by jraivio           #+#    #+#             */
/*   Updated: 2022/05/14 23:11:17 by jraivio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asteriod.h>

double	get_distance(t_vector first, t_vector second)
{
	return (sqrt((first.x - second.x) * (first.x - second.x)
				+(first.y - second.y) * (first.y - second.y)));
}
