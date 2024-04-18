/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:38:28 by maustel           #+#    #+#             */
/*   Updated: 2024/02/18 18:38:28 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_numbers(t_pslist *a_stack)
{
	t_pslist	*temp;

	temp = a_stack;
	ft_printf ("\n[cont]		[rel]\n");
	while (temp)
	{
		ft_printf ("[%d]		[%d]\n", (temp->content), temp->rel);
		temp = temp->next;
	}
}

/*if there is only one argument (./push_swap) or two arguments but
the second is empty (""), return (0)
if there are only two arguments ("1 5 2"), split it into single arguments.
*/

/* void leaks( void ) { // remove
 	system("leaks push_swap");
 }
 atexit(leaks);
*/

int	main(int argc, char **argv)
{
	t_pslist	*a_stack;
	t_pslist	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (1);
		if (!argv[0])
			return (free(argv), 1);
	}
	else
		argv++;
	if (!prep_input(argv, &a_stack, argc))
		return (write(2, "Error\n", 6));
	cont_relative(&a_stack, get_size_stack(a_stack));
	if (!sorting(&a_stack, &b_stack))
		return (1);
	set_free(&a_stack, &b_stack, argv, argc);
	return (0);
}
