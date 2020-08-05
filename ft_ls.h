#ifndef FT_LS_H
#define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <unistd.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <fcntl.h>
# include "libft/ft_printf/ft_printf.h"

# define FLAG_NON	0x0			// without flags
# define FLAG_L		0x1			// -l
# define FLAG_A		0x2			// -a
# define FLAG_R		0x4			// -R
# define FLAG_T		0x8			// -t
# define FLAG_MIN_R	0x10		// -r
# define FLAG_ARG	0x20		// more than one argument

typedef struct		s_crutch
{
    char    			*way;
    int     			flags;
    int     			count;
	int					arg;
	int					fail;
}                   t_crutch;

typedef struct		s_head
{
	struct	stat     	stat;
	struct	s_list		*arg_start;
	struct	s_list		*fail_start;
}                   t_head;

typedef struct		s_opt
{
    size_t             olink;
    size_t             osize;
    size_t             opwd;
    size_t             ogrp;
    int                r_maj;
    int                r_min;
}                   t_opt;

typedef struct		s_list
{
    char                *dir;
	char				*name;
	char				*path;
	struct s_list   	*child;
	struct stat     	stat;
	char                *link;
	char                *pwd;
	char                *grp;
	int                 rdev_maj;
	int                 rdev_min;
	int                 format;

	struct	s_list		*next;
}                   t_list;

char    	*ft_parsing(char **argv, char *way, int *flags, int *count);
t_list     	*ft_fail_create(t_crutch *data, t_list *failp);
char		*slash_strjoin(char const *s1, char const *s2);
t_list    	*ft_arg_create(t_crutch *data, t_list *argp);
void        process(t_list *cur, char *name,char *way);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_printf_exit(char *str, t_list *list);
t_list    	*ft_start_file(char *way, t_list *names);
int        	conditions(t_list *a, t_list *b, int i);
t_list     	*in_directory(char *way, t_list *names);
t_list     	*process_arg(t_list *cur, char *way);
int     	time_rev_sort(t_list *a, t_list *b);
void        ft_perror(char *str, t_list *list);
char    	*ft_findlastname(const char *path);
int     	time_sort(t_list *a, t_list *b);
int        	is_it_sorted(t_list *nm, int i);
t_list      *sort_list(t_list *lst, int i);
void        copy(t_list *p1, t_list *p2);
t_list      *sorting(t_list *nm, int i);
void        swap(t_list *a, t_list *b);
void        user_and_group(t_list *nm);
int         are_you_dir(t_list *cur);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void        about_file(t_list *nm);
void		ft_null(t_list *list);
void        type_file(t_list *nm);
void        file_mode(int mode);
int         print(t_list *nm);
void        big_str(t_list *nm);
void        ft_total(t_list *nm);


void            format_num(int date, int big);
size_t             len_num(int src);
size_t             len_link(t_list *nm);
t_opt           *parse_big(t_list *nm);
size_t             len_pwd(t_list *nm);
void            format_str(char *src, size_t big);

void            soft_link(char *way);

void            format_time(time_t date);

int             len_min(t_list *nm);
int             len_maj(t_list *nm);

void            format_maj_size(t_list *nm, t_opt *lst);
void            format_min_size(t_list *nm, t_opt *lst);

#endif