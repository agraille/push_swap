/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:19:54 by agraille          #+#    #+#             */
/*   Updated: 2024/12/09 15:06:40 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int find_pivot(t_stack *stack)
{
    int *sorted;
    int pivot;
    int i;
    int j;
    int tmp;

    sorted = malloc(sizeof(int) * (stack->top + 1));
    if (!sorted)
        return (0);
    i = -1;
    while (++i <= stack->top)
        sorted[i] = stack->data[i];
    i = 0;
    while (i <= stack->top)
    {
        j = 0;
        while (j < stack->top - i)
        {
            if (sorted[j] > sorted[j + 1])
            {
                tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    pivot = sorted[stack->top / 2];
    free(sorted);
    return (pivot);
}

int is_sorted(t_stack *stack)
{
    int i;

    i = stack->top;
    while (i > 0)
    {
        if (stack->data[i] > stack->data[i - 1])
            return (0);
        i--;
    }
    return (1);
}


void sort_stack_b(t_stack *a, t_stack *b)
{
    int max_index;

    while (b->top != -1)
    {
        max_index = b->top;

        // Trouver l'élément maximum dans `stack_b`
        for (int i = b->top - 1; i >= 0; i--)
        {
            if (b->data[i] > b->data[max_index])
                max_index = i;
        }

        // Ramener l'élément maximum en haut de `stack_b`
        if (max_index == b->top)
        {
            pa(a, b); // Pousse dans `stack_a` si déjà en haut
        }
        else if (max_index >= b->top / 2)
        {
            ra_rb(b, 'b'); // Effectuer une rotation si l'élément est proche du haut
        }
        else
        {
            rra_rrb(b, 'b'); // Effectuer une rotation inverse si proche du bas
        }
    }
}


void push_swap(t_stack *a, t_stack *b)
{
    // int pivot;
    // int pushed;
    // int size;

    while (!is_sorted(a))
    {
        // size = a->top + 1; // Taille actuelle de stack_a
        // pushed = 0;
        // pivot = find_pivot(a);

        // Pousser les éléments <= pivot dans stack_b
        while (a->top >= 0)
        {
            if (a->data[a->top])
            {
                pb(a, b);
                // pushed++;
            }
            else
            {
                ra_rb(a, 'a');
            }
        }

        // Trier les éléments dans stack_b et les remettre dans stack_a
        sort_stack_b(a, b);
    }
}




