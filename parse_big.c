#include "ft_ls.h"

size_t            len_num(int src)
{
    int         res;

    res = 1;
    while (src/10)
    {
        res += 1;
        src = src / 10;
    }
    return (res);
}

size_t             len_grp(t_list *nm)
{
    size_t         res;

    res = ft_strlen(nm->grp);
    while (nm)
    {
        if (res < ft_strlen(nm->grp))
            res = ft_strlen(nm->grp);
        nm = nm->next;
    }
    res = len_num(res);
    return (res);
}

size_t            len_pwd(t_list *nm)
{
    size_t         res;

    res = ft_strlen(nm->pwd);
    while (nm)
    {
        if (res < ft_strlen(nm->pwd))
            res = ft_strlen(nm->pwd);
        nm = nm->next;
    }
    res = len_num(res);
    return (res);
}

size_t             len_size(t_list *nm)
{
    int         res;

    res = nm->stat.st_size;
    while (nm)
    {
        if (res < nm->stat.st_size)
            res = nm->stat.st_size;
        nm = nm->next;
    }
    res = len_num(res);
    return (res);
}

size_t             len_link(t_list *nm)
{
    int         res;

    res = nm->stat.st_nlink;
    while (nm)
    {
        if (res < nm->stat.st_nlink)
            res = nm->stat.st_nlink;
       nm = nm->next;
    }
    res = len_num(res);
    return (res);
}

t_opt           *parse_big(t_list *nm)
{
    t_opt       *lst;

    lst = (t_opt *)malloc(sizeof(t_opt));

    lst->osize = len_size(nm);
    lst->olink = len_link(nm);
    lst->opwd = len_pwd(nm);
    lst->ogrp = len_grp(nm);
        return (lst);
}