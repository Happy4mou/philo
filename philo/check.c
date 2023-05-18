/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:18:03 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 17:29:21 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_check_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 1)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_checkargs(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == 0)
		{
			printf("Eroor: zero!\n");
			return (1);
		}
		if (ft_check_isdigit(av[i]) == 0)
			i++;
		else
		{
			printf("Eroor : non digite!\n");
			return (1);
		}
	}
	return (0);
}
