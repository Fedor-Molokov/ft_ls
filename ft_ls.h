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
# include <limits.h>
# include "libft/ft_printf/ft_printf.h"

# define INVALID_ARG	-1			// invalid argument
# define VALID_ARG_DIR	1			// valid argument - directory
# define VALID_ARG_FILE	2			// valid argument is not a directory

# define FLAG_NON		0x0			// without flags
# define FLAG_L			0x1			// -l
# define FLAG_A			0x2			// -a
# define FLAG_R			0x4			// -R
# define FLAG_T			0x8			// -t
# define FLAG_MIN_R		0x10		// -r
# define FLAG_ARG		0x20		// more than one argument
# define FLAG_NEXT		0x40		// go to next arg

// nm->file == 0 ? about_file(nm) : 1;

typedef struct			s_crutch
{
	char				*way;
	int					flags;
	int					count;
	int					arg;
	int					fail;
}						t_crutch;

typedef struct			s_head
{
	int					valid;
	struct stat			stat;
	struct s_list		*val_file_start;
	struct s_list		*val_dir_start;
	struct s_list		*invalid_start;
}						t_head;

typedef struct			s_opt
{
	size_t				olink;
	size_t				osize;
	size_t				opwd;
	size_t				ogrp;
	size_t				r_maj;
	size_t				r_min;
	int					spec;
}						t_opt;

typedef struct			s_list
{
	char				*dir;
	char				*name;
	char				*path;

	struct s_list		*child;
	struct stat			stat;
	char				*link;
	char				*pwd;
	char				*grp;
	int					rdev_maj;
	int					rdev_min;
	int					format;
	int					file;

	struct s_list		*next;

}						t_list;

char					*ft_parsing(char **argv, char *way,/
int *flags, int *count);
void					process(t_list *cur, char *name, char *way, int flags);
t_list					*in_directory(char *way, t_list *names, int flags);
t_list					*ft_invalid_create(t_crutch *data, t_list *failp);
void					ft_init(t_head *head, t_crutch *data, int file);
char					*slash_strjoin(char const *s1, char const *s2);
void					if_valid_arg_file(t_head *head, t_crutch *data);
void					if_valid_arg_dir(t_head *head, t_crutch *data);
void					while_arg_dir(t_list *arg_dir, t_crutch data);
t_list					*ft_file_create(t_crutch *data, t_list *argp);
t_list					*ft_dir_create(t_crutch *data, t_list *argp);
void					if_invalid_arg(t_head *head, t_crutch *data);
int						ft_strcmp(const char *s1, const char *s2);
t_list					*ft_start_file(char *way, t_list *names);
int						conditions(t_list *a, t_list *b, int i);
int						ft_printf_exit(char *str, t_list *list);
void					format_maj_size(t_list *nm, t_opt *lst);
void					format_min_size(t_list *nm, t_opt *lst);
t_list					*process_arg(t_list *cur, char *way);
int						time_rev_sort(t_list *a, t_list *b);
void					ft_perror(char *str, t_list *list);
char					*ft_findlastname(const char *path);
void					format_num_o(int date, size_t big);
t_opt					*parse_big(t_list *nm, int flags);
void					format_str(char *src, size_t big);
void					print_list(t_list *nm, int flags);
void					format_str(char *src, size_t big);
t_opt					*parse_big(t_list *nm, int flags);
void					format_num(int date, size_t big);
int						time_sort(t_list *a, t_list *b);
int						is_it_sorted(t_list *nm, int i);
void					ft_total(t_list *nm, int flags);
size_t					len_link(t_list *nm, int flags);
void					if_child(t_list *nm, int flags);
void					ft_total(t_list *nm, int flags);
t_list					*sort_list(t_list *lst, int i);
size_t					len_pwd(t_list *nm, int flags);
void					big_str(t_list *nm, int flags);
size_t					len_pwd(t_list *nm, int flags);
int						len_min(t_list *nm, int flags);
int						len_maj(t_list *nm, int flags);
int						ft_start(int flags, char *way);
void					big_str(t_list *nm, int flags);
void					copy(t_list *p1, t_list *p2);
int						print(t_list *nm, int flags);
t_list					*sorting(t_list *nm, int i);
void					swap(t_list *a, t_list *b);
void					begin_of_list(t_list *nm);
void					begin_of_list(t_list *nm);
int						are_you_dir(t_list *dir);
int						are_you_dir(t_list *cur);
size_t					ft_strlen(const char *s);
void					format_time(time_t date);
char					*ft_strnew(size_t size);
void					about_file(t_list *nm);
int						type_file(t_list *nm);
void					ft_null(t_list *list);
int						crutch(t_list *list);
void					soft_link(char *way);
void					ft_free(t_list *nm);
int						is_spec(t_list *nm);
void					file_mode(int mode);
void					file_mode(int mode);
void					ft_free(t_list *nm);
size_t					len_num(int src);

#endif
