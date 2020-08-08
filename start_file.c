/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarsell <dmarsell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 01:54:40 by dmarsell          #+#    #+#             */
/*   Updated: 2020/08/08 07:39:12 by dmarsell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list    *ft_file_create(t_crutch *data, t_list *argp)
{
    if (!(argp->next = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_file_create() malloc: ", NULL);
    if(lstat(data->way, &argp->stat) < 0)
        ft_perror("ft_file_create() lstat: ", NULL);
    argp = argp->next;
    ft_null(argp);
    argp->name = ft_strdup(data->way);
    argp->path = ft_strdup(data->way);
    argp->file = 1;
    data->arg++;
    return(argp);
}

t_list    *ft_dir_create(t_crutch *data, t_list *argp)
{
    if (!(argp->next = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_dir_create() malloc: ", NULL);
    if(lstat(data->way, &argp->stat) < 0)
        ft_perror("ft_dir_create() lstat: ", NULL);
    argp = argp->next;
    ft_null(argp);
    argp->name = ft_findlastname(data->way);
    argp->path = ft_strdup(data->way);
    if (argp->file)                                             //
        ft_printf("argp->file: %d\n", argp->file);          //
    argp->file = 0;
    data->arg++;
    return(argp);
}

t_list     *ft_invalid_create(t_crutch *data, t_list *failp)
{
    if (!(failp->next = (t_list *)malloc(sizeof(t_list))))
        ft_perror("ft_invalid_create() malloc: ", NULL);
    failp = failp->next;
    ft_null(failp);
    failp->name = ft_findlastname(data->way);
    failp->path = ft_strdup(data->way);
    data->fail++;
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
    names->child = NULL;
    names->next = NULL;
    return (names);
}