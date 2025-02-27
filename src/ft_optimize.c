/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:23:59 by ldummer-          #+#    #+#             */
/*   Updated: 2025/02/27 19:39:01 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_moves(t_stack *node)
{
	t_stack	rot_both;
	t_stack	rev_rot_both;
	t_stack	single_rot;

	rot_both = *node;
	rev_rot_both = *node;
	single_rot = *node;
	ft_optimize_rotations(&rot_both);
	ft_optimize_rev_rotations(&rev_rot_both);
	ft_optimize_single_rotations(&single_rot);
	if (ft_total_moves(&rot_both)->total_steps
		< ft_total_moves(&rev_rot_both)->total_steps)
		*node = rot_both;
	else
		*node = rev_rot_both;
	if (ft_total_moves(&single_rot)->total_steps < node->total_steps)
		*node = single_rot;
}

void	ft_optimize_rotations(t_stack *rot)
{
	if (rot->ra > rot->rb)
		rot->rr = rot->rb;
	else
		rot->rr = rot->ra;
	rot->ra -= rot->rr;
	rot->rb -= rot->rr;
	rot->rrb = 0;
	rot->rra = 0;
}

void	ft_optimize_rev_rotations(t_stack *rev_rot)
{
	if (rev_rot->rra > rev_rot->rrb)
		rev_rot->rrr = rev_rot->rrb;
	else
		rev_rot->rrr = rev_rot->rra;
	rev_rot->rra -= rev_rot->rrr;
	rev_rot->rrb -= rev_rot->rrr;
	rev_rot->rb = 0;
	rev_rot->ra = 0;
}

void	ft_optimize_single_rotations(t_stack *single)
{
	if (single->ra > single->rra)
		single->ra = 0;
	else
		single->rra = 0;
	if (single->rb > single->rrb)
		single->rb = 0;
	else
		single->rrb = 0;
}
