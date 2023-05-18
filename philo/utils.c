/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:21:51 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 08:04:06 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	rst;
	int				s;

	i = 0;
	s = 1;
	rst = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rst = rst * 10 + str[i] - 48;
		i++;
	}
	if (rst >= 9223372036854775807 && s == 1)
		return (-1);
	else if (rst > 9223372036854775807 && s == -1)
		return (0);
	return (rst * s);
}

long	ft_gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_initial_helper(int i, t_strack_p *ph, char **av)
{
	ph[i].args.philo = ft_atoi(av[1]);
	ph[i].args.ttd = ft_atoi(av[2]);
	ph[i].args.tte = ft_atoi(av[3]);
	ph[i].args.tts = ft_atoi(av[4]);
}

void	ft_initial(int ac, t_strack_p *ph, char **av, pthread_mutex_t *b)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&ph[i].l_forck, NULL);
		ph[i].start = ft_gettime();
		ph[i].helpmtx = b;
		ph[i].eat = ft_gettime();
		ft_initial_helper(i, ph, av);
		ph[i].id = i + 1;
		if (ac == 5)
			ph[i].args.cer = 0;
		else
			ph[i].args.cer = ft_atoi(av[5]);
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]) - 1)
	{
		ph[i].r_forck = &ph[i + 1].l_forck;
		i++;
	}
	ph[i].r_forck = &ph[0].l_forck;
}

void	ft_usleep(long h)
{
	long	t;

	t = ft_gettime();
	while (ft_gettime() - t < h)
		usleep(1000);
}
