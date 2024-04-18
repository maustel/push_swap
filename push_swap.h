/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:13:16 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 09:13:16 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# include <stdio.h>
# include <string.h>

typedef struct p_list
{
	int				content;
	int				rel;
	struct p_list	*next;
}					t_pslist;

long		ft_atol(const char *str);

void		set_free(t_pslist **a, t_pslist **b, char **argv, int argc);

t_pslist	*create_node(int data, int rel);
t_pslist	*add_node_back(t_pslist **lst, int data);
t_pslist	*add_node_front(t_pslist **lst, int data, int rel);
t_pslist	**delete_first(t_pslist **lst);

void		swap(t_pslist **lst, char *str);
void		rotate(t_pslist **lst, char *str);
void		rotate_reverse(t_pslist **lst, char *str);
t_pslist	**push(t_pslist **a, t_pslist **b, char *str);

int			prep_input(char **argv, t_pslist	**a_stack, int argc);

int			get_size_stack(t_pslist *stack);
t_pslist	*get_lowest(t_pslist *a_stack);

void		cont_relative(t_pslist **a_stack, int size);

t_pslist	*sorting(t_pslist **a_stack, t_pslist **b_stack);
t_pslist	*sort_three(t_pslist **a_stack);
t_pslist	*sort_five(t_pslist **a_stack, t_pslist **b_stack);

void		free_argv(char **str);

#endif
