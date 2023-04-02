/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:21:51 by atucci            #+#    #+#             */
/*   Updated: 2023/04/02 14:36:18 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
// This function sends a single bit (either 0 or 1) to the server
void	send_bit(int server_pid, int bit)
{
// Send SIGUSR1 to the server if the bit is 1, otherwise send SIGUSR2
	if (bit)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
// Wait for a short time before sending the next bit
	usleep(100);
}
// This function sends a message to the server by converting 
// each character into a serives of bits
void	send_message(int server_pid, char *message)
{
	int	bit_index;
	int	bit_mask;

	bit_index = 0; // this is the index of the Current bit being sent
	bit_mask = 1 << 7; // Start with the most significant bit (bit 7)

// send each character in the message as a series of bits
	while (message[bit_index / 8])
	{
		while (bit_mask)
		{
		// send the current bit to the server
			send_bit(server_pid, message[bit_index / 8] & bit_mask);
		// shift the bit mask to the next bit position
			bit_mask >>= 1;
			bit_index++;
		}
	// Reset the bit mask to the most significan bit
		bit_mask = 1 << 7;
	}
	while (bit_mask)
	{
		send_bit(server_pid, 0); //Send the 0 bits to represent the null character
		bit_mask >>= 1;
	}
}
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
