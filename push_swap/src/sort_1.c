/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlee <najlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:32:32 by najlee            #+#    #+#             */
/*   Updated: 2021/05/26 21:32:33 by najlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_to_b(t_info *info, int r)
{
	int ra_;
	int pb_;
	int rb_;
	int i;
	int *pivot;

	ra_ = 0;
	pb_ = 0;
	rb_ = 0;
	i = -1;
	pivot = find_pivot(info, A, r);
	if (r <= 3)
		return (sort_a(info, r));
	while (r--)
	{
		if (info->stack[A]->head->next->data >= pivot[1])
		{
			rab(info, A, 1);
			ra_++;
		}
		else
		{
			pab(info, B);
			pb_++;
			if (info->stack[B]->head->next->data >= pivot[0] && info->stack[B]->size > 1)
			{
				rab(info, B, 1);
				rb_++;
			}
			else if (info->stack[B]->head->next->data >= pivot[0])
			{
				rb_++;
			}
		}
	}
	int tmp_ra = ra_;
	int tmp_rb = rb_;
	int tmp_pb = pb_;
	if (ra_ == info->stack[A]->size)
		ra_ = 0;
	if (rb_ == info->stack[B]->size)
		rb_ = 0;
	if ((info->stack[B]->size - rb_) < rb_)
	{
		if ((ra_ + info->stack[B]->size - rb_) < max(ra_, rb_))
		{
			rb_ = info->stack[B]->size - rb_;
			i = -1;
			while (++i < ra_)
				rrab(info, A, 1);
			i = -1;
			while (++i < rb_)
				rab(info, B, 1);
		}
	}
	else{
		i = -1;
		while (++i < min(ra_, rb_))
			rrr(info);
		i = -1;
		if (ra_ > rb_)
		{
			while (++i < ra_ - rb_)
				rrab(info, A, 1);
		}
		else
		{
			while (++i < rb_ - ra_)
				rrab(info, B, 1);
		}
	}
	a_to_b(info, tmp_ra);
	b_to_a(info, tmp_rb);
	b_to_a(info, tmp_pb - tmp_rb);
}

void	b_to_a(t_info *info, int r)
{
	int rb_;
	int pa_;
	int ra_;
	int	i;
	int	*pivot;

	rb_ = 0;
	pa_ = 0;
	ra_ = 0;
	i = -1;
	if (r <= 3)
		return (sort_b(info, r));
	pivot = find_pivot(info, B, r);
	while (r--)
	{
		if (info->stack[B]->head->next->data < pivot[0])
		{
			rab(info, B, 1);
			rb_++;
		}
		else
		{
			pab(info, A);
			pa_++;
			if (info->stack[A]->head->next->data < pivot[1] && info->stack[A]->size > 1)
			{
				rab(info, A, 1);
				ra_++;
			}
			else if (info->stack[A]->head->next->data < pivot[1])
			{
				ra_++;
			}
		}
	}
	int tmp_ra = ra_;
	int tmp_rb = rb_;
	int tmp_pa = pa_;
	a_to_b(info, tmp_pa - tmp_ra);
	if (ra_ == info->stack[A]->size)
		ra_ = 0;
	if (rb_ == info->stack[B]->size)
		rb_ = 0;
	if (ra_ < rb_)
	{
		i = -1;
		while (++i < ra_)
			rrr(info);
		i = -1;
		while (++i < rb_ - ra_)
			rrab(info, B, 1);
	}
	else{
		i = -1;
		while (++i < rb_)
			rrr(info);
		i = -1;
		while (++i < ra_ - rb_)
			rrab(info, A, 1);
	}
	a_to_b(info, tmp_rb);
	b_to_a(info, tmp_ra);
}
