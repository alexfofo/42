#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>

#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>

void	ft_exit(char *msg, char *options, char *word);
int		checkOption(char *options, char c, char *ref);
int		checkSpecialOptions(int *tmp, int *index, char *word);
char	*getOptions(int argc, char **argv, int *index);
char	**getArgs(int argc, char **argv, int firstArg);

void	printLastModifTime(time_t mtime);
void	printOptionL(char *path, char *name);
int		computeBlocks(char *path, char *options);
void	optionLilL(char *path, char **elemsToShow, int totBlock, int nbElem);


#endif