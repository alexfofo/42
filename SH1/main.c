/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:22:52 by afollin           #+#    #+#             */
/*   Updated: 2015/04/22 18:11:29 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h> // chdir, execve
#include <sys/wait.h> // wait

char	*ft_strcat_in_new_str(char *s1, char *s2)
{
	int			i;
	int			sz_1;
	int			sz_2;
	char		*ret;

	i = 0;
	sz_1 = ft_strlen(s1);
	sz_2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (sz_1 + sz_2 + 1));
	ft_bzero(ret, sz_1 + sz_2 + 1);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}

char    *duplicate_str(char *str)
{
	char		*dup;
	int			str_size;
	int			size;

	str_size = ft_strlen(str);
	size = str_size + 1;
	dup = (char *)malloc(sizeof(char) * size);
	ft_bzero(dup, size);
	if (str_size > 0)
		ft_strcat(dup, str);
	return (dup);
}

int			cmp_spe(char *s1, char *s2, char ref){
	int		i;
	int		j;
	
	i = -1;
	while (s1[++i] && s1[i] != ref)
		;
	if (!s1[i])
		return (-1);
	j = -1;

	while (++j < i){
		if (s1[j] != s2[j])
			return (-1);
	}
	if (s2[j])
		return (-1);
	return (0);
}

char		**cp_tab_str(char **tab)
{
	char		**ret;
	int			tab_len;
	int			count;

	ret = NULL;
	if (tab == NULL || tab[0] == NULL){
		ret = (char **)malloc(sizeof(char *) * 1);
		ret[0] = NULL;
		return (ret);
	}
	tab_len = -1;
	while (tab[++tab_len] && tab[tab_len][0])
		;
	ret = (char **)malloc(sizeof(char *) * (tab_len + 1));
	count = -1;
	while (++count < tab_len)
		ret[count] = duplicate_str(tab[count]);
	ret[count] = NULL;
	return (ret);
}

void    print_tab_str(char **tab)
{
	int             i;

	i = -1;
	while (tab && tab[++i])
		ft_putendl(tab[i]);
	return ;
}

void		early_exit(int argc, char **argv)
{
	int		i;

	i = -1;
	argc = 0;
	ft_putstr("usage: ");
	ft_putendl(argv[0]);
	exit(0);
	return ;
}

int			count_word(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '	')
			++i;
		while (str[i] && str[i] != ' ' && str[i] != '	')
		{
			++i;
			if (!str[i] || str[i] == ' ' || str[i] == '	')
				++count;
		}
	}
	return (count);
}

char		*get_word_x(char *str, int x)
{
	char		*ret;
	int			i;
	int			j;
	int			count;

	ret = NULL;
	i = 0;
	count = 0;
	while (str[i] && count < x)
	{
		while (str[i] == ' ' || str[i] == '	')
			++i;
		while (str[i] && str[i] != ' ' && str[i] != '	')
		{
			++i;
			if (!str[i] || str[i] == ' ' || str[i] == '	')
				++count;
		}

	}
	while (str[i] == ' ' || str[i] == '	')
		++i;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '	')
		++j;
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	ft_bzero(ret, j - i + 1);
	count = -1;
	while (++count < j - i)
		ret[count] = str[i + count];
	return (ret);
}

char		*get_word_x_spe(char *str, int x, char c)
{
	char		*ret;
	int			i;
	int			j;
	int			count;

	ret = NULL;
	i = 0;
	count = 0;
	while (str[i] && count < x)
	{
		while (str[i] == c)
			++i;
		while (str[i] && str[i] != c)
		{
			++i;
			if (!str[i] || str[i] == c)
				++count;
		}
	}
	if (!str[i] && count < x)
		return (NULL);
	while (str[i] == c)
		++i;
	j = i;
	while (str[j] && str[j] != c)
		++j;
	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	ft_bzero(ret, j - i + 1);
	count = -1;
	while (++count < j - i)
		ret[count] = str[i + count];
	return (ret);
}

char		**add_to_env(char **tab, char *keyword, char *value)
{
	char		**ret;
	char		*tmp;
	int			tab_len;
	int			count;
	int			flag_key;

	flag_key = 1;
	ret = NULL;
	if (tab == NULL || tab[0] == NULL){
		ret = (char **)malloc(sizeof(char *) * 2);
		ret[1] = NULL;
		count = 0;
		if (tab != NULL)
			free(tab);
	}
	else {
		tab_len = -1;
		while (tab[++tab_len] && tab[tab_len][0])
			flag_key = !cmp_spe(tab[tab_len], keyword, '=') ? 0 : flag_key;
		ret = (char **)malloc(sizeof(char *) * (tab_len + 1 + flag_key));
		ret[tab_len + flag_key] = NULL;
		count = -1;
		while (++count < tab_len)
		{
			if (cmp_spe(tab[count], keyword, '='))
				ret[count] = duplicate_str(tab[count]);
			else{
				tmp = ft_strcat_in_new_str(keyword, "=");
				ret[count] = ft_strcat_in_new_str(tmp, value);
			}
			free(tab[count]);
		}
		free(tab);
	}
	if (flag_key == 1){
		tmp = ft_strcat_in_new_str(keyword, "=");
		ret[count] = ft_strcat_in_new_str(tmp, value);
		free(tmp);
	}
	return (ret);
}

char	**remove_from_env(char **env, char *keyword){
	int 		tab_len;
	int 		flag_key;
	int 		count;
	int 		index;
	char		**ret;

	flag_key = -1;
	if (env == NULL || env[0] == NULL){
		ft_putendl("env is null, nothing to remove from env");
		return env;
	}
	tab_len = -1;
	while (env[++tab_len] && env[tab_len][0])
		flag_key = !cmp_spe(env[tab_len], keyword, '=') ? tab_len : flag_key;
	if (flag_key == -1){
		ft_putendl("keyword not not found");
		return (env);
	}
	else
		ret = (char **)malloc(sizeof(char *) * tab_len);
	ret[tab_len - 1] = NULL;
	count = -1;
	index = -1;
	while (++count < tab_len){
		if (cmp_spe(env[count], keyword, '='))
			ret[++index] = duplicate_str(env[count]);
		free(env[count]);
	}
	free(env);


	return (ret);
}

char		**do_setenv(char *line, char **env)
{
	int		i;
	char	*keyword;
	char	*value;
	char	**ret;

	i = -1;
	if (count_word(line) != 3)
	{
		ft_putendl("usage: setenv {keyword} {value}");
		return (env);
	}
	keyword = get_word_x(line, 1);
	value = get_word_x(line, 2);
	ret = add_to_env(env, keyword, value);
	return (ret);
}

char		**do_unsetenv(char *line, char **env)
{
	char	*keyword;

	if (count_word(line) != 2)
	{
		ft_putendl("usage: unsetenv {keyword}");
		return (env);
	}
	keyword = get_word_x(line, 1);
	env = remove_from_env(env, keyword);
	return (env);
}

char		**env_stuff(char *line, int *f, char **env)
{
	if (*f)
		return env;
	if (!ft_strcmp(line, "env")){
		print_tab_str(env);
		*f = 1;
	}
	else if (!ft_strncmp(line, "setenv", 6)){
		env = do_setenv(line, env);
		*f = 1;
	}
	else if (!ft_strncmp(line, "unsetenv", 8)){
		env = do_unsetenv(line, env);
		*f = 1;
	}

	return (env);
}

void		cd_stuff(char *line, int *f)
{
	int 		ret;
	static char 		buf[256];
	char 		*word_1;
	char 		*word_2;

	if (*f)
		return ;
	word_1 = get_word_x(line, 0);
	if (ft_strcmp(word_1, "cd")){
		free(word_1);
		return ;
	}
	if (count_word(line) != 2)
	{
		ft_putendl("usage: cd {directory}");
		free(word_1);
		return ;
	}
	word_2 = get_word_x(line, 1);
	if (!ft_strcmp(word_2, "-")){
		ret = chdir(buf);
	}
	else {
		getcwd(buf, 256);//il faut changer ca, il faudra use la var d'env OLDPATH
		ret = chdir(word_2);
	}

	//faire "cd", qui use $HOME pour aller a HOME ^^
	if (ret == -1)
		ft_putendl_fd("Impossible de changer de repertoire.", 2);
	free(word_1);
	free(word_2);
	*f = 1;
	return ;

}

char 		*find_exec_path(char *env_path, char *cmd) // attention a bien envoyer env + 5
{
	int 		i;
	char 		*tmp;
	char 		*tmp2;

	i = -1;
	while ((tmp = get_word_x_spe(env_path, ++i, ':')) != NULL){
		tmp2 = ft_strcat_in_new_str(tmp, "/");
		free(tmp);
		tmp = ft_strcat_in_new_str(tmp2, cmd);
		free(tmp2);
		if (access(tmp, F_OK) != -1)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

void		do_exec(char *path_to_exec, char **tab_str, char **env)
{
	pid_t		father;
	int 		child_status;

	father = fork();
	if (father > 0)
		wait(&child_status);
	if (father == 0)
		execve(path_to_exec, tab_str, env);
	return ;
}

void		execute_stuff(char **tab_str, int *f, char **env){
	char 	*path_to_exec;
	int 	i;

	i = -1;
	path_to_exec = NULL;
	if (*f)
		return ;
	while (env[++i] && cmp_spe(env[i], "PATH", '='))
		;
	if (!env[i])
		return ;
	path_to_exec = find_exec_path(env[i] + 5, tab_str[0]);
	if (path_to_exec != NULL){
		*f = 1;
		do_exec(path_to_exec, tab_str, env);
	}
	return ;
}

int 		go_gnl(int i, char **line)
{
	ft_putstr("\e[1;37m#$^&\e[0;31m42\e[1;37m*>> \e[0m");
	return (get_next_line(i, line));
}

void		unknown_cmd(char *line, int f)
{
	if (ft_strcmp(line, "42") == 0)
		ft_putendl_fd("RPZ ma ptite gueule", 2);
	else if (f == 0)
		ft_putendl_fd("Unknown command", 2);
	return ;
}

int			main(int argc, char **argv, char **env)
{
	char		**cp_env;
	char		*line;
	int			cute_flag;

	if (argc != 1)
		early_exit(argc, argv);
	cp_env = cp_tab_str(env);
	cute_flag = 0;
	while (go_gnl(0, &line) > 0)
	{
		if (!line || !line[0]){
			continue ;
		}
		if (ft_strcmp(line,"exit") == 0)
			return (1);
		cp_env = env_stuff(line, &cute_flag, cp_env);
		cd_stuff(line, &cute_flag);
		execute_stuff(ft_strsplit(line, ' '), &cute_flag, cp_env);
		unknown_cmd(line, cute_flag);
		cute_flag = 0;
	}
	return (0);
}
