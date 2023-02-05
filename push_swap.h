/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:36 by ajari             #+#    #+#             */
/*   Updated: 2023/02/05 00:22:38 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "ft_printf/printf.h"
# include "libft/libft.h"

void	fill_stack(t_list **lst, int ac, char **av);
void	swap(t_list **lst, char c);
void	ss(t_list **a, t_list **b);
void	retate(t_list **a, char c);
void	onti_retate(t_list **lst, char c);
void	rr(t_list **a, t_list **b);
void	push(t_list **lst_src, t_list **lst_dest, char c);
void	print_stack(t_list *list);
void	sort_three(t_list **lst, char c);
void	sort_five(t_list **a, t_list **b);
t_list	*min(t_list *lst, int sort);
t_list	*max(t_list *lst);
void	put_idx(t_list *lst);
int		search_idx(t_list *a, t_list *b);
int		r_or_rr(t_list *list, t_list *ma_min);
int		chek_sort(t_list *lst);
void	push_max(t_list **src, t_list **dst, char srcc, char dstc);
void	move_quarter(t_list **a, t_list **b, int start, int end);
int		r_or_rrr(t_list *list, t_list *ma_min);
void	repush_to_a(t_list **src, t_list **dst, char srcc, char dstc);
int		there_is_more_to_push(t_list *lst, int start, int end);
void	sort_five_handred(t_list **a, t_list **b);
#endif