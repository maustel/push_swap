/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:44:18 by maustel           #+#    #+#             */
/*   Updated: 2024/02/23 17:44:18 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_pslist *a_stack)
{
	while (a_stack->next)
	{
		if (a_stack->rel < a_stack->next->rel)
			a_stack = a_stack->next;
		else
			return (0);
	}
	return (1);
}

/*find highest number and count it's bits*/

int	get_bits(t_pslist	**a_stack)
{
	int			highest;
	int			bits;
	t_pslist	*temp;

	temp = *a_stack;
	highest = temp->rel;
	while (temp)
	{
		if (temp->rel > highest)
			highest = temp->rel;
		temp = temp->next;
	}
	bits = 0;
	while (highest)
	{
		highest = highest >> 1;
		bits++;
	}
	return (bits);
}

/*check for every number of the stack each bit if set (=1) or not (=0)
startig from the right.
if set, rotate stack, of not push it to b*/

t_pslist	*bit_shift(t_pslist **a_stack, t_pslist **b_stack, int size, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a_stack)->rel >> i) & 1)
			rotate(a_stack, "ra\n");
		else
		{
			if (!push(a_stack, b_stack, "pb\n"))
				return (NULL);
		}
		j++;
	}
	return (*a_stack);
}

/*when input is less than 6 numbers, it gets handled differently, because
it's required by the subject.
get_bits searches for the highest number and counts its bits. so we know
how many times we have to do the algorithm.
bit_shift is the first part of the algorithm. When finished, the second part
is pushing every element from b_stack back to a_stack*/

t_pslist	*sorting(t_pslist **a_stack, t_pslist **b_stack)
{
	int	bit_nbr;
	int	i;
	int	size;

	if (is_sorted(*a_stack))
		return (*a_stack);
	size = get_size_stack(*a_stack);
	if (size == 2 || size == 3)
		return (sort_three(a_stack));
	if (size == 4 || size == 5)
		return (sort_five(a_stack, b_stack));
	bit_nbr = get_bits(a_stack);
	i = 0;
	while (i < bit_nbr)
	{
		bit_shift(a_stack, b_stack, size, i);
		while (*b_stack)
		{
			if (!push(b_stack, a_stack, "pa\n"))
				return (NULL);
		}
		i++;
	}
	return (*a_stack);
}
