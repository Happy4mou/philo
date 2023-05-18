/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:57 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 17:29:35 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_break(int ac, t_strack_p *phil)
{
	while (1)
	{
		if (ac == 6 && ft_cer(phil) == 1)
			break ;
		if (ft_dead(phil) == 0)
			break ;
	}
}

void	*ft_manag(void *ph)
{
	t_strack_p	*p;

	p = (t_strack_p *)ph;
	if (p->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		ft_eating(p);
		ft_sleeping(p);
		ft_think(p);
	}
}

int	main(int ac, char **av)
{
	int				i;
	t_strack_p		*phil;
	pthread_t		*ph;
	pthread_mutex_t	*o;

	o = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(o, NULL);
	if (ac != 5 && ac != 6)
		return (1);
	if (ft_checkargs(av) == 1)
		return (1);
	i = 0;
	phil = malloc(ft_atoi(av[1]) * sizeof(t_strack_p));
	ph = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	ft_initial(ac, phil, av, o);
	while (i < ft_atoi(av[1]))
	{
		pthread_create(&ph[i], NULL, ft_manag, &phil[i]);
		i++;
	}
	ft_break(ac, phil);
}
