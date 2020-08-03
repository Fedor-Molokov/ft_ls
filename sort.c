#include "ft_ls.h"

void        copy(t_list *p1, t_list *p2)
{
    p1->name = p2->name;
    p1->path = p2->path;
    p1->stat = p2->stat;
    p1->child = p2->child;
}


void        swap(t_list *a, t_list *b)
{
    t_list  tmp;

    tmp = *a;
    copy(a, b);
    copy(b, &tmp);
}

int        is_it_sorted(t_list *nm, int i)
{
    while (nm->next)
    {
        if (i == 2 && ft_strcmp(nm->name, nm->next->name) < 0)
            return (0);
        if (i == 1 && ft_strcmp(nm->name, nm->next->name) > 0)
            return (0);
        if (i == 3)
            if (time_sort(nm, nm->next))
                return (0);
        if (i == 4)
            if (time_rev_sort(nm, nm->next))
                return(0);
        nm = nm->next;
    }
    return (1);
}

int      conditions(t_list *a, t_list *b, int i)
{
    if (i == 2)
        if (ft_strcmp(a->name, b->name) < 0)
            return (1);
    if (i == 1)
        if (ft_strcmp(a->name, b->name) > 0)
            return (1);
     if (i == 3)
        if (time_sort(a, b))
            return (1);
   if (i == 4)
        if (time_rev_sort(a, b))
            return (1);
    return (0);
}

t_list      *sort_list(t_list *lst, int i)
{
    t_list  *a;
    t_list  *b;
    t_list  *cur;

    a = lst;
    b = lst->next;
    cur = lst;
    while (b)
    {
        // if (a->name && b->name)
        // {
            if (conditions(a, b, i))
                swap(a, b);
        // }
        a = a->next;
        b = b->next;
    }
    if (!(is_it_sorted(cur, i)))
        sort_list(lst, i);
    return (lst);
}

t_list        *sorting(t_list *nm, int i)
{
    t_list  *head;
    t_list  *cur;

    if (!(head = (t_list *)malloc(sizeof(t_list))))
        ft_perror("sorting() malloc: ", nm);
    head->next = nm;
    sort_list(nm, i);
    cur = head->next;
    while (cur)
    {
        if(cur->child)
            sorting(cur->child, i);
        cur = cur->next;
    }
    free(head);
    return (head->next);
}