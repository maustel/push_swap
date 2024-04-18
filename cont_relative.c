/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_relative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:40:54 by maustel           #+#    #+#             */
/*   Updated: 2024/03/10 14:40:54 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*look for the node with the content is equal to given max and
set its relative value*/

void	set_rel(t_pslist **a_stack, int max, int rel)
{
	t_pslist	*temp;

	temp = *a_stack;
	while (temp)
	{
		if (temp->content == max)
		{
			temp->rel = rel;
			return ;
		}
		temp = temp->next;
	}
}

/*create relative content (for ex when there are 10 numbers, cont_rel
will be between 1 (lowest value) and 10 (highest value))to reduce the
number of moves and to handle negative numbers. Initial value of every
temp->rel is 0. This makes it possible to check, if the rel_value is already
set or not.
The second while-loop searches for the maximum value, that is not set yet.
when found, value will be set. The first while-loop counts down from the
highest possible rel_value to the lowest (1).*/

void	cont_relative(t_pslist **a_stack, int size)
{
	int			max;
	int			rel;
	t_pslist	*temp;

	rel = size;
	while (rel > 0)
	{
		max = (get_lowest(*a_stack))->content;
		temp = *a_stack;
		while (temp)
		{
			if (temp->rel == 0 && max < temp->content)
				max = temp->content;
			temp = temp->next;
		}
		set_rel(a_stack, max, rel);
		rel--;
	}
}
