/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:48:11 by maustel           #+#    #+#             */
/*   Updated: 2024/03/09 13:48:11 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if there are only two numbers and the first is bigger than second, swap.
with 3 numbers (call them a, b, c): if a bigger than b and c, rotate.
If a bigger b but smaller than c, swap.
If a smaller than b but bigger than c, reverse rotate. */

t_pslist	*sort_three(t_pslist **a_stack)
{
	int	i;

	if (get_size_stack(*a_stack) == 2)
	{
		if ((*a_stack)->rel > (*a_stack)->next->rel)
			swap(a_stack, "sa\n");
		return (*a_stack);
	}
	i = 0;
	while (i < 3)
	{
		if ((*a_stack)->rel > (*a_stack)->next->rel)
		{
			if ((*a_stack)->rel > (*a_stack)->next->next->rel)
				rotate(a_stack, "ra\n");
			else
				swap(a_stack, "sa\n");
		}
		else if ((*a_stack)->next->rel > (*a_stack)->next->next->rel)
			rotate_reverse(a_stack, "rra\n");
		i++;
	}
	return (*a_stack);
}

int	get_sec_lowest(t_pslist *a_stack, int lowest)
{
	t_pslist	*temp;
	int			seclow;

	temp = a_stack;
	seclow = temp->rel;
	while (temp)
	{
		if (seclow == lowest)
			seclow = temp->rel;
		if (temp->rel < seclow && temp->rel != lowest)
			seclow = temp->rel;
		temp = temp->next;
	}
	return (seclow);
}

t_pslist	*push_lowest(t_pslist **a_stack, t_pslist **b_stack, int seclow)
{
	while (get_size_stack(*a_stack) > 3)
	{
		if ((*a_stack)->rel > seclow)
			rotate(a_stack, "ra\n");
		else
		{
			if (!push(a_stack, b_stack, "pb\n"))
				return (NULL);
		}
	}
	return (*a_stack);
}

/*4 numbers: find lowest and push it to b, than sort a_stack with sort_three
and push lowest back to a.
5 numbers: find lowest and second lowest and push them to b. Sort them
in order to have the lowest in the end. Sort rest of a_stack with sort_three,
Push lowest numbers back to a_stack.*/

t_pslist	*sort_five(t_pslist **a_stack, t_pslist **b_stack)
{
	int	lowest;
	int	seclow;

	lowest = (get_lowest(*a_stack))->rel;
	if (get_size_stack(*a_stack) == 4)
		seclow = lowest;
	else
		seclow = get_sec_lowest(*a_stack, lowest);
	if (!push_lowest(a_stack, b_stack, seclow))
		return (NULL);
	if (get_size_stack(*a_stack) == 3)
		sort_three(a_stack);
	while ((*b_stack)->next)
	{
		if ((*b_stack)->rel < (*b_stack)->next->rel)
			swap(b_stack, "sb\n");
		else
		{
			if (!push(b_stack, a_stack, "pa\n"))
				return (NULL);
		}
	}
	if (!push(b_stack, a_stack, "pa\n"))
		return (NULL);
	return (*a_stack);
}
