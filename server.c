/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkidd <nkidd@student.42adel.org.au>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:37:40 by nkidd             #+#    #+#             */
/*   Updated: 2022/12/28 15:37:57 by nkidd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/includes/ft_printf.h"
t_message		g_msg;

void	bit_handler_zero()
{
		signal(SIGUSR1, bit_handler_zero);
		g_msg.i++;
		if (g_msg.i == 7)
		{
				ft_printf("%c", g_msg.c);
				if (!g_msg.c)
						ft_printf("\n");
				g_msg.c = 0;
				g_msg.i = 0;
		}
}

void	bit_handler_one()
{
		signal(SIGUSR2, bit_handler_one);
		g_msg.c ^= (1 << g_msg.i);
		g_msg.i++;
		if (g_msg.i == 7)
		{
				ft_printf("%c", g_msg.c);
				if (!g_msg.c)
						ft_printf("\n");
				g_msg.c = 0;
				g_msg.i = 0;
		}
}

int main(void)
{
	g_msg = (t_message){0,0};
	if (g_msg.i){}
	ft_printf("Welcome To My Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	signal(SIGUSR2, bit_handler_one);
	signal(SIGUSR1, bit_handler_zero);
	while (1)
			usleep(1000);
	return (0);
}