/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:00:43 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/04/16 08:00:01 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct t_strackh
{
	int				philo;
	int				ttd;
	int				tte;
	int				tts;
	int				cer;
}					t_strack_help;

typedef struct t_strackp
{
	long			start;
	long			eat;
	int				num_eat;
	int				id;
	pthread_mutex_t	*r_forck;
	pthread_mutex_t	l_forck;
	pthread_mutex_t	*helpmtx;

	t_strack_help	args;

}					t_strack_p;

int					ft_isdigit(char c);
int					ft_check_isdigit(char *s);
int					ft_checkargs(char **av);
int					ft_atoi(const char *str);
long				ft_gettime(void);
void				ft_initial(int ac, t_strack_p *ph, char **av,
						pthread_mutex_t *b);
void				ft_usleep(long h);
void				ft_eating(t_strack_p *ph);
int					ft_dead(t_strack_p *ph);
void				ft_sleeping(t_strack_p *ph);
void				*ft_manag(void *ph);
int					ft_cer(t_strack_p *ph);
void				ft_print(char *s, t_strack_p *ph);
void				ft_initial_helpre(int i, t_strack_p *ph, char **av);
void				ft_break(int ac, t_strack_p *phil);
void				ft_think(t_strack_p *ph);

#endif
