/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   node_utils.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: maustel <maustel@student.42heilbronn.de	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/14 12:38:06 by maustel		   #+#	#+#			 */
/*   Updated: 2024/02/14 12:38:06 by maustel		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	set_free(t_pslist **a_stack, t_pslist **b_stack, char **argv, int argc)
{
	t_pslist	*temp;

	temp = NULL;
	if (a_stack)
	{
		while (*a_stack)
		{
			temp = *a_stack;
			*a_stack = temp->next;
			free(temp);
			temp = NULL;
		}
	}
	if (b_stack)
	{
		while (*b_stack)
		{
			temp = *b_stack;
			*b_stack = temp->next;
			free(temp);
			temp = NULL;
		}
	}
	if (argc == 2)
		free_argv(argv);
}

t_pslist	*create_node(int data, int rel)
{
	t_pslist	*node;

	node = malloc (sizeof(t_pslist));
	if (!node)
		return (NULL);
	node->content = data;
	node->rel = rel;
	node->next = NULL;
	return (node);
}

t_pslist	*add_node_back(t_pslist **lst, int data)
{
	t_pslist	*node;
	t_pslist	*tmp;

	node = create_node(data, 0);
	if (!node)
		return (NULL);
	if (*lst == NULL)
		*lst = node;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (*lst);
}

t_pslist	*add_node_front(t_pslist **lst, int data, int rel)
{
	t_pslist	*node;

	node = create_node(data, rel);
	if (!node)
		return (NULL);
	node->next = *lst;
	*lst = node;
	return (*lst);
}

t_pslist	**delete_first(t_pslist **lst)
{
	t_pslist	*tmp;

	if (!*lst)
		return (NULL);
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	free (tmp);
	return (lst);
}
