/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecerquei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:00:05 by ecerquei          #+#    #+#             */
/*   Updated: 2019/12/10 14:14:09 by ecerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_variables(int *signal, unsigned int *result, int *i);
int		ft_isspace(char c);
int		update_result(unsigned int *result, char c);
int		ft_isnumeric(char c);

int		ft_atoi(char *str)
{
	int				i;
	int				signal;
	unsigned int	result;

	init_variables(&signal, &result, &i);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (update_result(&result, str[i]) == 0)
			return (signal * result);
		i++;
	}
	return (signal * result);
}

void	init_variables(int *signal, unsigned int *result, int *i)
{
	*signal = 1;
	*result = 0;
	*i = 0;
}

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

int		ft_isnumeric(char c)
{
	return (c >= '0' && c <= '9');
}

int		update_result(unsigned int *result, char c)
{
	if (ft_isnumeric(c))
	{
		*result *= 10;
		*result += c - '0';
		return (1);
	}
	return (0);
}
