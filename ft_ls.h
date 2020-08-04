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

typedef struct		s_list
{
	char				*name;
	char				*path;
	struct s_list   	*child;
	struct stat     	stat;
	char                *link;

	struct	s_list		*next;
}                   t_list;

char    	*ft_parsing(char **argv, char *way, int *flags, int *count);
char		*slash_strjoin(char const *s1, char const *s2);
void        process(t_list *cur, char *name,char *way);
int			ft_strcmp(const char *s1, const char *s2);
t_list		*ft_printf_exit(char *str, t_list *list);
t_list    	*ft_start_file(char *way, t_list *names);
int        	conditions(t_list *a, t_list *b, int i);
t_list     	*in_directory(char *way, t_list *names);
int     	time_rev_sort(t_list *a, t_list *b);
void        ft_perror(char *str, t_list *list);
int     	time_sort(t_list *a, t_list *b);
int        	is_it_sorted(t_list *nm, int i);
t_list      *sort_list(t_list *lst, int i);
void        copy(t_list *p1, t_list *p2);
t_list      *sorting(t_list *nm, int i);
void        swap(t_list *a, t_list *b);
int         are_you_dir(t_list *cur);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void        about_file(t_list *nm);
void		ft_null(t_list *list);
char        *get_name(char *obj);
void        type_file(int mode);
void        file_mode(int mode);
void        user_and_group(t_list *nm);
void        read_link(char *path);
void        hardlink(int link);

#endif