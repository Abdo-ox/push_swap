/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:36 by ajari             #+#    #+#             */
/*   Updated: 2023/02/02 17:26:01 by ajari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void	swap(t_list **lst, char c);
void	swap_a_and_b(t_list **a, t_list **b);
void	retate(t_list **a, char c);
void	retate_a_and_b(t_list **a, t_list **b);
void	onti_retate(t_list **lst, char c);
void	push(t_list **lst_src, t_list **lst_dest, char c);
void	print_stack(t_list *list);
int		*sort_stack_in_arry(t_list **lst);
void	sort_arr_put_index(t_list *lst, int *n, int size);
void	sort_three(t_list **lst, char c);
t_list	*min(t_list *lst, int sort);
t_list	*max(t_list *lst);
void	put_index(t_list *lst);
void	fill_stack(t_list **lst, int ac, char **av);
void	print_arry(int *n, int size);
int		search_index(t_list *a, t_list *b);
int		probabelite(t_list *list, int size);
t_list	*lst_large(t_list *list);
int		retate_or_onti(t_list *lst, int first, int last);
void	sort_five(t_list **a, t_list **b);
void	move_quarter(t_list **a, t_list **b, int size, int d);
int		r_or_rr(t_list *list, t_list *ma_min);
int		chek_sort(t_list *lst);
void	repush_to_a(t_list **a, t_list **b, char c, char d);
int		where_big_percentage(t_list *lst, t_list *lst2, int size, int d);
void	move_quarter_five_handred(t_list **a, t_list **b, int siz, int d);

#endif