/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:14:24 by maustel           #+#    #+#             */
/*   Updated: 2024/03/08 15:14:24 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_stack(t_pslist *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/*get stack with lowest content*/

t_pslist	*get_lowest(t_pslist *a_stack)
{
	int			lowest;
	t_pslist	*temp;

	temp = a_stack;
	lowest = temp->content;
	while (temp)
	{
		if (temp->content < lowest)
			lowest = temp->content;
		temp = temp->next;
	}
	temp = a_stack;
	while (temp)
	{
		if (temp->content == lowest)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

long	ft_atol(const char *str)
{
	long	nbr;
	long	minus;

	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	minus = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	nbr = 0;
	while (str && '0' <= *str && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * minus);
}

void	free_argv(char **str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free (str);
}
