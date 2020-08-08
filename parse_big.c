#include "ft_ls.h"

size_t          len_num(int src)
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

size_t          len_num_o(int src)
{
	int         res;

	res = 1;
	while (src / 16)
	{
		res += 1;
		src = src / 16;
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

int             len_maj(t_list *nm)
{
    int         tmp;
    int         res;

    tmp = nm->rdev_maj;
    while (nm)
    {
        if (tmp < nm->rdev_maj)
            tmp = nm->rdev_maj;
        nm = nm->next;
    }
    res = len_num(tmp);
    return (res);
}

int             len_min(t_list *nm)
{
    int         tmp;
    int         res;

    tmp = 0;
    res = 0;
    while(nm)
    {
        if (tmp < nm->rdev_min)
            tmp = nm->rdev_min;
        nm = nm->next;
    }
    res = len_num(tmp);
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
    lst->r_min = len_min(nm);
    lst->r_maj = len_maj(nm);
    return (lst);
}