/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:25:07 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 07:57:47 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_strack_p *ph)
{
	pthread_mutex_lock(&ph->l_forck);
	ft_print("has taken a fork", ph);
	pthread_mutex_lock(ph->r_forck);
	ft_print("has taken a fork", ph);
	ft_print("is eating", ph);
	pthread_mutex_lock(ph->helpmtx);
	ph->eat = ft_gettime();
	ph->num_eat++;
	pthread_mutex_unlock(ph->helpmtx);
	ft_usleep(ph->args.tte);
	pthread_mutex_unlock(&ph->l_forck);
	pthread_mutex_unlock(ph->r_forck);
}

int	ft_dead(t_strack_p *ph)
{
	int		i;
	long	t;

	i = 0;
	while (i < ph->args.philo)
	{
		t = ft_gettime();
		pthread_mutex_lock(ph->helpmtx);
		if (t - ph[i].eat > ph->args.ttd)
		{
			printf("%ld\t %d : died\n", t - ph->start, ph[i].id);
			return (0);
		}
		pthread_mutex_unlock(ph->helpmtx);
		i++;
	}
	return (1);
}

void	ft_sleeping(t_strack_p *ph)
{
	ft_print("is sleeping", ph);
	ft_usleep(ph->args.tts);
}

void	ft_think(t_strack_p *ph)
{
	ft_print("is thinking", ph);
}

int	ft_cer(t_strack_p *ph)
{
	int	i;
	int	eat;

	i = 0;
	eat = 0;
	while (i < ph->args.philo)
	{
		pthread_mutex_lock(ph->helpmtx);
		if (ph[i].num_eat >= ph->args.cer)
			eat++;
		pthread_mutex_unlock(ph->helpmtx);
		i++;
	}
	if (eat == ph->args.philo)
		return (1);
	return (0);
}
