/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:21:51 by atucci            #+#    #+#             */
/*   Updated: 2023/04/02 13:49:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	int		server_pid;	// this is the process ID of the process 
	char	*message;
	
	if (ac != 3)
	{
		// write something here
		return (1);
	}

	server_pid = ft_atoi(av[1]); // ascii to int for the first message (?)
	message = av[2]; //  assign the second string to the previously  declared message

	// calling the function send_message
	send_message(server_pid, message);

	return(0);
}
