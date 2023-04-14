/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:21:51 by atucci            #+#    #+#             */
/*   Updated: 2023/04/06 18:06:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
// This function sends a single bit (either 0 or 1) to the server
void	send_bit(int server_pid, int q)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (q & (1 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}
// This function sends a message to the server by converting 
// each character into a serives of bits
void	send_message(pid_t pid, char *message)
{
	int	count;
   
	count = 0;
	while (message[count] != '\0')
	{
		send_bit(pid, message[count]);
		usleep(100);
		count++;
	}
}
void	receipt(int f)
{
	(void)f;
	ft_printf("\033[32m%s\033[0m\n", "message receipt\n");
}

int	main(int ac, char *av[])
{
	int		server_pid;	// this is the process ID of the process 
	char	*message;
	
	if (ac != 3)
	{
		// write something here
		ft_printf("\033[31mthe fuck are you doing bro?\n Check yourself!\033[31m\n");
		return (1);
	}

	server_pid = ft_atoi(av[1]); // ascii to int for the first message (?)
	message = av[2]; //  assign the second string to the previously  declared message
	send_message(server_pid, message); // calling the function send  message
	signal(SIGUSR1, receipt); // print  the receipt 
	send_bit(server_pid, '\n');
	send_bit(server_pid, '\0');

	return(0);
}
