#include "ft_ls.h"

int     time_rev_sort(t_list *a, t_list *b)
{
    if (a->stat.st_mtime > b->stat.st_mtime)
        return (1);
    else if (a->stat.st_mtime == b->stat.st_mtime)
    {
        if (a->stat.st_mtime > b->stat.st_mtime)
            return (1);
        if (a->stat.st_mtime == b->stat.st_mtime)
        {
            if (ft_strcmp(a->name, b->name) < 0)
                return (1);
        }
    }
    return (0);
}

int     time_sort(t_list *a, t_list *b)
{
    if (a->stat.st_mtime < b->stat.st_mtime)
        return (1);
    else if (a->stat.st_mtime == b->stat.st_mtime)
    {
        if (a->stat.st_mtime < b->stat.st_mtime)
            return (1);
        if (a->stat.st_mtime == b->stat.st_mtime)
        {
            if (ft_strcmp(a->name, b->name) > 0)
                return (1);
        }
    }
    return (0);
}