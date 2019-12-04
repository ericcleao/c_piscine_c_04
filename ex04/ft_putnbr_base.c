/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecerquei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:29:12 by ecerquei          #+#    #+#             */
/*   Updated: 2019/12/04 16:03:19 by ecerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_get_base_lenght(char *base);
void			ft_putchar(char c);
void			ft_putnbr(int nb, unsigned int base_len, char *base);

void			ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				signal;
	unsigned int	result;
	unsigned int	base_len;

	signal = 1;
	result = 0;
	i = 0;
	base_len = ft_get_base_lenght(base);
	if (base_len != 0)
	{
		ft_putnbr(nbr, base_len, base);
	}
}

unsigned int	ft_get_base_lenght(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void			ft_putnbr(int nb, unsigned int base_len, char *base)
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
	if (positive_nbr >= base_len)
	{
		ft_putnbr(positive_nbr / base_len, base_len, base);
	}
	ft_putchar(base[(positive_nbr % base_len)]);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}
