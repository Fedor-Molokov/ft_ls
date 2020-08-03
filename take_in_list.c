/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 01:03:54 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 00:44:53 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void            print(t_list *nm)
{
    int     i;
    t_list  *cur;

    i = 0;
    cur = nm;
    while(cur)
    {
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
}

char            *get_name(char *obj)
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
        ft_perror("in_directory() opendir: ", names);           // ft_printf("./ft_ls: %s: No such file or directory\n", names->path);
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

void    ft_start(int flags, char *way)
{
    t_list  *names;
    t_list  *go;
    
    if (!(names = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_start() malloc: ", names);
    ft_null(names);
    go = in_directory(way, names);
    go = sorting(go, flags);
    print(go);
}

int     main(int argc, char **argv)
{
    char    *way;
    int     flags;
    int     count;
      
    // flags = 1;
    flags = 0;
    count = 1;
    if (argc == 1)
    {
        way = "./";
        flags = FLAG_NON;
        ft_start(flags, way);
    }
    while(argv[count])
    {
        way = ft_parsing(argv, way, &flags, &count);
        ft_start(flags, way);
    }
    return (0);
}