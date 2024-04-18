/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:18:49 by maustel           #+#    #+#             */
/*   Updated: 2024/02/23 18:18:49 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pslist **lst, char *str)
{
	t_pslist	*ptr;
	int			tmp;
	int			tmp_rel;

	if (!lst || !*lst || !str)
		return ;
	ptr = *lst;
	if (!ptr->next)
		return ;
	tmp = ptr->content;
	tmp_rel = ptr->rel;
	ptr->content = ptr->next->content;
	ptr->rel = ptr->next->rel;
	ptr->next->content = tmp;
	ptr->next->rel = tmp_rel;
	ft_printf("%s", str);
}

void	rotate(t_pslist **lst, char *str)
{
	t_pslist	*ptr;
	t_pslist	*head;

	if (!lst || !*lst || !str)
		return ;
	ptr = *lst;
	if (!ptr->next)
		return ;
	head = ptr->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *lst;
	ptr->next->next = NULL;
	*lst = head;
	ft_printf("%s", str);
}

void	rotate_reverse(t_pslist **lst, char *str)
{
	t_pslist	*head;

	if (!lst || !*lst || !str)
		return ;
	head = *lst;
	while (head->next->next)
		head = head->next;
	head->next->next = *lst;
	*lst = head->next;
	head->next = NULL;
	ft_printf("%s", str);
}

t_pslist	**push(t_pslist **a, t_pslist **b, char *str)
{
	t_pslist	*ptr;

	if (!*a)
		return (NULL);
	if (!a || !b || !str)
	{
		set_free(a, b, NULL, 0);
		return (NULL);
	}
	ptr = *a;
	if (!add_node_front(b, ptr->content, ptr->rel))
	{
		set_free(a, b, NULL, 0);
		return (NULL);
	}
	if (!delete_first(a))
	{
		set_free(a, b, NULL, 0);
		return (NULL);
	}
	ft_printf("%s", str);
	return (a);
}
