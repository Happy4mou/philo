/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:05:35 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 07:59:57 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *s, t_strack_p *ph)
{
	pthread_mutex_lock(ph->helpmtx);
	printf("%ld\t %d : %s\n", ft_gettime() - ph->start, ph->id, s);
	pthread_mutex_unlock(ph->helpmtx);
}
