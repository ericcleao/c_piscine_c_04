/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecerquei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:48:28 by ecerquei          #+#    #+#             */
/*   Updated: 2019/12/04 15:21:27 by ecerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_base_lenght(char *base);
int	ft_convert_char(char c, char *base);
int	ft_isspace(char c);
int	ft_update_result(unsigned int *result, char c, char *base, int base_len);

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				signal;
	unsigned int	result;
	int				base_len;

	signal = 1;
	result = 0;
	i = 0;
	base_len = ft_get_base_lenght(base);
	if (base_len != -1)
	{
		while (ft_isspace(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				signal *= -1;
		}
		while (str[i] != '\0')
		{
			if (ft_update_result(&result, str[i++], base, base_len) == -1)
				return (signal * result);
		}
	}
	return (signal * result);
}

int	ft_get_base_lenght(char *base)
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
				return (-1);
			j++;
		}
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	ft_convert_char(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
	{
		i++;
	}
	if (base[i] == '\0')
	{
		return (-1);
	}
	return (i);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_update_result(unsigned int *result, char c, char *base, int base_len)
{
	int current_digit;

	current_digit = ft_convert_char(c, base);
	if (current_digit != -1)
	{
		*result *= base_len;
		*result += current_digit;
	}
	return (current_digit);
}
