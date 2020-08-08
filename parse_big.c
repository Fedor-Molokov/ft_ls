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

/*size_t          len_num_o(int src, int flags)
{
	int         res;

	res = 1;
	while (src / 16)
	{
		res += 1;
		src = src / 16;
	}
	return (res);
}*/

size_t             len_grp(t_list *nm, int flags)
{
    size_t         res;

    res = 0;
    while (nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else {
				if (res < ft_strlen(nm->grp))
					res = ft_strlen(nm->grp);
				nm = nm->next;
			}
    }
    return (res);
}

size_t            len_pwd(t_list *nm, int flags)
{
    size_t         res;

    res = 0;
    while (nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
			{
				if (res < ft_strlen(nm->pwd))
					res = ft_strlen(nm->pwd);
				nm = nm->next;
		}
    }
    return (res);
}

size_t             len_size(t_list *nm, int flags)
{
    int         res;

    res = 0;
    while (nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
			{
				if (res < nm->stat.st_size)
					res = nm->stat.st_size;
				nm = nm->next;
			}
    }
    res = len_num(res);
    return (res);
}

size_t             len_link(t_list *nm, int flags)
{
    int         res;

    res = 0;
    while (nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else
			{
				if (res < nm->stat.st_nlink)
					res = nm->stat.st_nlink;
				nm = nm->next;
			}
    }
    res = len_num(res);
    return (res);
}

int             len_maj(t_list *nm, int flags)
{
    int         tmp;
    int         res;

    tmp = 0;
    while (nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
        else
        	{
				if (tmp < nm->rdev_maj)
						tmp = nm->rdev_maj;
				nm = nm->next;
			}
    }
    res = len_num(tmp);
    return (res);
}

int             len_min(t_list *nm, int flags)
{
    int         tmp;
    int         res;

    tmp = 0;
    res = 0;
    while(nm)
    {
		if (!(flags & FLAG_A) && nm->name[0] == '.' && nm->file == 0)
			nm = nm->next;
		else {
			if (tmp < nm->rdev_min)
				tmp = nm->rdev_min;
			nm = nm->next;
		}
    }
    res = len_num(tmp);
    return (res);
}

int 		is_spec(t_list *nm)
{
	int res;

	res = 0;
	while (nm)
	{
		if ((S_ISCHR(nm->stat.st_mode)) || (S_ISBLK(nm->stat.st_mode)))
		{
			res = 1;
			return (res);
		}
		nm = nm->next;
	}
	return (res);
}

t_opt           *parse_big(t_list *nm, int flags)
{
    t_opt       *lst;

    lst = (t_opt *)malloc(sizeof(t_opt));
    lst->osize = len_size(nm, flags);
    lst->olink = len_link(nm, flags);
    lst->opwd = len_pwd(nm, flags);
    lst->ogrp = len_grp(nm, flags);
    lst->r_min = len_min(nm, flags);
    lst->r_maj = len_maj(nm, flags);
	lst->spec = is_spec(nm);
    return (lst);
}