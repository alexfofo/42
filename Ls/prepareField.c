#include "libft.h"
#include "ft_ls.h"

void	ft_exit(char *msg, char *options, char *word)
{
	//free(options);
	if (!options)
		exit(1);
	ft_putstr(msg);
	ft_putendl(word);
	exit(0);
	return ;
}

int		checkOption(char *options, char c, char *ref)
{
	int flag;

	flag = -1;
	while (*ref) // le char ne fait pas parti des options supportées
	{
		if (c == *ref)
			flag = 1;
		++ref;
	}
	while (*options && flag > 0) // le char est deja dans options
	{
		if (c == *options)
			flag = 0;
		++options;
	}
	return (flag);
}

int		checkSpecialOptions(int *tmp, int *index, char *word)
{
	if (ft_strncmp(word, "-", ft_strlen(word)) == 0){
		--(*index);
		return (1);
	}
	if (ft_strncmp(word, "--", ft_strlen(word)) == 0){
		*tmp = 0;
		return (1);
	}
	return (0);
}

char	*getOptions(int argc, char **argv, int *index) // retourne un char* contenant les options passées and SET index
{
	char		*options;
	int			opt;
	int			j;
	int			tmp;
	int			breakFlag;

	options = (char *)malloc(sizeof(char) * 6);
	ft_bzero(options, 6);
	if ((opt = 0) == 0 && (breakFlag = 0) == 0 && argc == 1) // economise deux lignes d'INITIALISATION
		return (options); // ici option est full of \0
	while (++(*index) < argc && argv[(*index)][0] == '-' && breakFlag == 0)
	{
		j = 0;
		while (argv[(*index)][++j])
		{
			if ((tmp = checkOption( options, argv[(*index)][j], "lRart\0" )) == 1)
				options[opt++] = argv[(*index)][j];
		}
		if (checkSpecialOptions(&tmp, index, argv[(*index)]) == 1)
			breakFlag = 1;
		if (tmp == -1)
			ft_exit("Problem, wrong option: ", options, argv[(*index)]);
	}
	return (options);
}

char	**getArgs(int argc, char **argv, int firstArg)
{
	char	**args;
	int		sub;
	int		i;

	if ((sub = argc - firstArg) == 0 || firstArg == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (sub + 1));
	i = -1;
	while (++i + firstArg < argc)
	{
		args[i] = (char *)malloc(sizeof(char) * (ft_strlen(argv[i + firstArg]) + 1));
		ft_strcpy(args[i], argv[i + firstArg]);
	}
	if (args && !(*args))
		return (NULL);
	return (args);
}