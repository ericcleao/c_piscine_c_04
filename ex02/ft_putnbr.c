/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecerquei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:31:02 by ecerquei          #+#    #+#             */
/*   Updated: 2019/12/03 09:43:09 by ecerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int positive_nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		positive_nbr = nb * (-1);
	}
	else
	{
		positive_nbr = nb;
	}
	if (positive_nbr >= 10)
	{
		ft_putnbr(positive_nbr / 10);
	}
	ft_putchar((positive_nbr % 10) + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
