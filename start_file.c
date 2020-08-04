/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 01:54:40 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/04 17:17:10 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list    *ft_arg_create(t_crutch *data, t_list *argp, t_head *head)
{
    if (!(argp = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_arg_create() malloc: ", NULL);
    ft_null(argp);
    data->arg++;
    if (data->arg > 1)
        data->flags |= FLAG_ARG;
    if(lstat(data->way, &argp->stat) < 0)
        ft_perror("ft_arg_create() lstat: ", NULL);
    argp->name = ft_findlastname(data->way);
    argp->path = ft_strdup(data->way);
    argp->next = NULL;
    return(argp);
}

t_list     *ft_fail_create(t_crutch *data, t_list *failp, t_head *head)
{
    if (!(failp = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_fail_create() malloc: ", NULL);
    ft_null(failp);
    data->fail++;
    failp->name = ft_findlastname(data->way);
    failp->path = ft_strdup(data->way);
    failp->next = NULL;
    return(failp);
}

char    *ft_fillname(char *newname, int i, int j, const char *path)
{
    int     count;

    count = 0;
    while(path[i] && j > 0)
    {
        newname[count] = path[i];
        count++;
        j--;
        i++;
    }
    return(newname);
}

char    *ft_findlastname(const char *path)
{
    char    *newname;
    int     slash;
    int     addslash;
    int     i;
    int     j;
    
    j = 0;
    i = ft_strlen(path);
    addslash = 0;
    slash = 0;
    while(i >= 0 && path)
    {
        if ((path[i] == '/' && path[i + 1] == '\0' && i != 1) 
        || (path[i] == '/' && path[i - 1] == '/'))
            addslash = 1;
        if (path[i] == '/' && path[i - 1] != '/' && path[i + 1] != '/' && i != 0)
            slash++;
        if ((slash == 2 && addslash == 1) || (slash == 1 && addslash == 0))
            break ;
        i--;
        j++;
    }
    newname = ft_strnew(j);
    return(ft_fillname(newname, i + 1, j, path));
}

t_list    *ft_start_file(char *way, t_list *names)
{
    names->name = ft_findlastname(way);
    names->path = ft_strdup(way);
    if(lstat(way, &names->stat) < 0)
        return (ft_printf_exit(names->name, names));
    names->child = NULL;
    names->next = NULL;
    return (names);
}