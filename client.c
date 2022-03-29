
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:58:09 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/29 14:32:33 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char bit)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bit & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit >>= 1;
		i++;
		usleep(100);
	}
}

static void	recived(int signal)
{
	if (signal == SIGUSR1)
		printf("message recived\n");
	return ;
}

void	caller(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i] != '\0')
		send_message(pid, message[i]);
	send_message(pid, '\n');
	send_message(pid, '\0');
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		exit (0);
	signal(SIGUSR1, recived);
	pid = ft_atoi(argv[1]);
	caller(pid, argv[2]);
}
