#include "ft_ls.h"

void        copy(t_list *p1, t_list *p2)
{
    p1->name = p2->name;
    p1->path = p2->path;
    p1->stat = p2->stat;
    p1->child = p2->child;
    p1->link = p2->link;
}


void        swap(t_list *a, t_list *b)
{
    t_list  tmp;

    tmp = *a;
    copy(a, b);
    copy(b, &tmp);
}

int        is_it_sorted(t_list *nm, int flags)
{
    while (nm->next)
    {
        if (flags == (FLAG_MIN_R | !(FLAG_T))
        && ft_strcmp(nm->name, nm->next->name) < 0)
            return (0);
        if (flags == (!(FLAG_T) | !(FLAG_MIN_R)) && ft_strcmp(nm->name, nm->next->name) > 0)
            return (0);
        if (flags == ((FLAG_T) | !(FLAG_MIN_R)))
            if (time_sort(nm, nm->next))
                return (0);
        if (flags == (FLAG_T | FLAG_MIN_R)) 
            if (time_rev_sort(nm, nm->next))
                return(0);
        nm = nm->next;
    }
    return (1);
}

int      conditions(t_list *a, t_list *b, int flags)
{
    if (flags == (FLAG_MIN_R | !(FLAG_T)))
        if (ft_strcmp(a->name, b->name) < 0)
            return (1);
    if (flags == (!(FLAG_T) | !(FLAG_MIN_R)))
        if (ft_strcmp(a->name, b->name) > 0)
            return (1);
    if (flags == ((FLAG_T) | !(FLAG_MIN_R)))
        if (time_sort(a, b))
            return (1);
    if (flags == (FLAG_T | FLAG_MIN_R))
        if (time_rev_sort(a, b))
            return (1);
    return (0);
}

t_list      *sort_list(t_list *lst, int flags)
{
    t_list  *a;
    t_list  *b;
    t_list  *cur;

    a = lst;
    b = lst->next;
    cur = lst;
    while (b)
    {
        if (conditions(a, b, flags))
            swap(a, b);
        a = a->next;
        b = b->next;
    }
    if (!(is_it_sorted(cur, flags)))
        sort_list(lst, flags);
    return (lst);
}

t_list        *sorting(t_list *nm, int flags)
{
    t_list  *head;
    t_list  *cur;

    if (nm == NULL)
        return (NULL);
    if (!(head = (t_list *)malloc(sizeof(t_list))))
        ft_perror("sorting() malloc: ", nm);
    ft_null(head);
    head->next = nm;
    sort_list(nm, flags);
    cur = head->next;
    while (cur)
    {
        if(cur->child)
            sorting(cur->child, flags);
        cur = cur->next;
    }
    free(head);
    return (head->next);
}