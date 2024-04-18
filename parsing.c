/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:35:07 by maustel           #+#    #+#             */
/*   Updated: 2024/02/18 18:35:07 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(t_pslist *a_stack)
{
	int			i;
	t_pslist	*temp;

	while (a_stack)
	{
		temp = a_stack;
		i = temp->content;
		while (temp->next)
		{
			temp = temp->next;
			if (i == temp->content)
				return (0);
		}
		a_stack = a_stack->next;
	}
	return (1);
}

int	check_nbrs(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*Check if only numbers, if overflow (more than 11 digits (INTMIN))
and in INT-range.
If ok, add node at back of stack*/

int	write_to_stack(char *str, t_pslist **a_stack)
{
	if (!str || !str[0] || ft_strlen(str) > 11 || !check_nbrs(str))
		return (0);
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	if (!add_node_back(a_stack, ft_atol(str)))
		return (0);
	return (1);
}

/*create stack and check for double numbers*/

int	prep_input(char **argv, t_pslist **a_stack, int argc)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!write_to_stack(argv[i], a_stack))
		{
			set_free(a_stack, NULL, argv, argc);
			return (0);
		}
		i++;
	}
	if (!check_dups(*a_stack))
	{
		set_free(a_stack, NULL, argv, argc);
		return (0);
	}
	return (1);
}
