/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:58:26 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/29 19:03:42 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if ((nb == 0 && power != 0) || power < 0)
		return (0);
	if ((power == 0) || ((nb < 0) && (power == 0)))
		return (1);
	else
	{
		while (power > 0)
		{
			result = nb * result;
			power--;
		}
		return (result);
	}
}

void	my_handler(int signum, siginfo_t *info, void *content)
{
	static int	ascii = 0;
	static int	power = 0;
	static int	client_pid;

	(void)content;
	if (info -> si_pid)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		ascii += ft_iterative_power(2, power);
	power += 1;
	if (power == 8)
	{
		if (ascii == 0)
			if (kill(client_pid, SIGUSR1) == -1)
				exit(0);
		write(1, &ascii, 1);
		power = 0;
		ascii = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = my_handler;
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (true)
		pause ();
}
