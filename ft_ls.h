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

typedef struct		s_list
{
	char				*name;
	char				*path;
	struct s_list   	*child;
	struct stat     	stat;

	struct	s_list		*next;
}                   t_list;

void		ft_null(t_list *list);
void        ft_perror(char *str);
t_list        *sorting(t_list *nm, int i);
int        conditions(t_list *a, t_list *b, int i);
int     time_sort(t_list *a, t_list *b);
int     time_rev_sort(t_list *a, t_list *b);
char            *get_name(char *obj);
t_list      *sort_list(t_list *lst, int i);
int        is_it_sorted(t_list *nm, int i);
void        swap(t_list *a, t_list *b);
void        copy(t_list *p1, t_list *p2);
t_list            *in_directory(char *way, t_list *names);
int            are_you_dir(t_list *cur);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*slash_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
void        process(t_list *cur, char *name,char *way);

#endif