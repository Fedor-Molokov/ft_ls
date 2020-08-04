/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 01:03:54 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 20:21:59 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int            print(t_list *nm)
{
    int     i;
    t_list  *cur;

    i = 0;
    cur = nm;
    while(cur)
    {
        if (lstat(cur->path, &cur->stat) < 0)
            ft_printf_exit(cur->name, cur);
        while (cur->name[i])
        {
            write(1, &cur->name[i], 1);
            i++;
        }
        write(1, "\n", 1);
        cur = cur->next;
        i = 0;
    }
    write(1, "\n", 1);
    while(nm)
    {
        if(nm->child)
            print(nm->child);
        nm = nm->next;
    }
    return (0);
}

char            *get_name(char *obj)                            // ft_strdup() ??
{
    int     l;
    int     i;
    char    *name;

    l = 0;
    i = 0;
    while (obj[l])
        l++;
    if (!(name = (char *)malloc(sizeof(char) * l + 1)))
        ft_perror("get_name() malloc: ", (t_list *) obj);
    while (i < l)
    {
        name[i] = obj[i];
        i++;
    }
    name[i] = '\0';
    return (name);
}

int         are_you_dir(t_list *dir)
{
    t_list      *new_dir;

    if (S_ISDIR(dir->stat.st_mode))
    {
        if (!(new_dir = (t_list *)malloc(sizeof(t_list))))
            ft_perror("are_you_dir() malloc: ", dir);
        ft_null(new_dir);
        dir->child = new_dir;
        new_dir->path = dir->path;
        return (1);
    }
    dir->child = NULL;
    return (0);
}

void        process(t_list *cur, char *name, char *way)
{
    cur->name = get_name(name);
    cur->path = slash_strjoin(way, cur->name);
    if(lstat(cur->path, &cur->stat) < 0)
        ft_perror("process() lstat: ", cur);
    if((ft_strcmp(cur->name, ".") != 0 ) && (ft_strcmp(cur->name, "..") != 0))
    {
        if (are_you_dir(cur))
            cur->child = in_directory(cur->path, cur->child);
    }
}

t_list     *in_directory(char *way, t_list *names)
{
    struct dirent   *entry;
    DIR             *dirp;
    t_list          *cur;

    if (!(dirp = opendir(way)))
        return (ft_start_file(way, names));
    if (!(entry = readdir(dirp)))
        ft_perror("in_directory() readdir: ", names);
    cur = names;
    while (entry)
    {
        process(cur, entry->d_name, way);
        if ((entry = readdir(dirp)))
        {
            if (!(cur->next = (t_list *)malloc(sizeof(t_list))))
                ft_perror("in_directory() malloc: ", cur);
            cur = cur->next;
            ft_null(cur);
        }
    }
    cur->next = NULL;
    if (closedir(dirp) < 0)
        ft_perror("in_directory() closedir: ", cur);
    return (names);
}

int    ft_start(int flags, char *way)
{
    t_list  *names;
    t_list  *go;
    
    if (way == NULL)
        return (-1);
    if (!(names = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_start() malloc: ", names);
    ft_null(names);
    go = in_directory(way, names);
    go = sorting(go, flags);
    return (print(go));
}

void    ft_init(t_head *head, t_crutch *data, int i)
{
    if (i == 1)
    {
        if (!(head->arg_start = (t_list *)malloc(sizeof(t_list))))
            ft_perror("ft_init() malloc: ", NULL);
        ft_null(head->arg_start);
        head->arg_start->name = ft_findlastname(data->way);
        head->arg_start->path = ft_strdup(data->way);
    }
    else if (i == 2)
    {
        if (!(head->fail_start = (t_list *)malloc(sizeof(t_list))))
            ft_perror("ft_init() malloc: ", NULL);
        ft_null(head->fail_start);
        head->fail_start->name = ft_findlastname(data->way);
        head->fail_start->path = ft_strdup(data->way);
    }
}

void    ft_prestart(t_head *head, char **argv, t_crutch *data)
{
    t_list          *argp;
    t_list          *failp;
    int             notfile;
    int             arg;
    
    arg = 0;
    notfile = 0;
    while(argv[data->count])
    {
        data->way = ft_parsing(argv, data->way, &data->flags, &data->count);
        if (lstat(data->way, &head->stat) < 0)
        {

            if (notfile == 0)
            { 
                ft_init(head, data, 2);
                failp = head->fail_start;
                notfile++;
                continue ;
            }
            failp = ft_fail_create(data, failp);
        }
        else
        {
            if (arg == 0)
            {
                ft_init(head, data, 1);
                argp = head->arg_start;
                arg++;
                continue ;
            }
            argp = ft_arg_create(data, argp);
        }
        // if (!(ft_start(data.flags, data.way)))
        //     continue;
    }
    if (arg)
        argp->next = NULL;
    if (notfile)
        failp->next = NULL;
}

int     main(int argc, char **argv)
{
    t_head          head;
    t_crutch        data;
    // t_list          *argp;
    // t_list          *failp;
    
    data.arg = 0;
    data.fail= 0;
    data.flags = 0;
    data.count = 1;
    if (argc == 1)
    {
        data.way = "./";
        data.flags = FLAG_NON;
        ft_start(data.flags, data.way);
    }
    ft_prestart(&head, argv, &data);
    // ft_init(&head);
    // while(argv[data.count])
    // {
    //     data.way = ft_parsing(argv, data.way, &data.flags, &data.count);
    //     if (lstat(data.way, &head.stat) < 0)
    //     {
    //         failp = ft_fail_create(&data, failp, &head);
    //         failp = failp->next;
    //     }
    //     else
    //     {
    //         argp = ft_arg_create(&data, argp, &head);
    //         argp = argp->next;
    //     }
    //     // if (!(ft_start(data.flags, data.way)))
    //     //     continue;
    // }
    return (0);
}