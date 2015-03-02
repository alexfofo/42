#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>

# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>

void	ft_exit(char *msg, char *options, char *word);
int		checkOption(char *options, char c, char *ref);
int		checkSpecialOptions(int *tmp, int *index, char *word);
char	*getOptions(int argc, char **argv, int *index);
char	**getArgs(int argc, char **argv, int firstArg);

void	printLastModifTime(time_t mtime);
void	printOptionL(char *path, char *name);
int		computeBlocks(char *path, char *options);
void	optionLilL(char *path, char **elemsToShow, int totBlock, int nbElem);

char	**extendTab(char **tab, char *name);
char	**sortOptionA(char *options, char *name, char **elemSorted, int *i);

char	**sortOptionLilT(char **oldTab, char *path, int count);
char	**sortOptionLilR(char **oldTab, char **newTab, int count);

int		strInTabStr(char *str, char **tab, int sizeTab);
char	*getBiggerStrInTab(char **tab, int count);
char	**sortInAscii(char **oldTab, char **newTab, int count);

char	*createStrSuffix(char *s1, char *s2);
int		ft_isDir(char *entityPath);
char	*duplicateStr(char *str);

void	optionBigR(char *path, char *options);

char	**getElemstoDisplay(char *options, char *name, int *nbElem);
char	**sortElems(char *options, char **elemToSort, char *path);
void	ft_ls(char *options, char **args, int ac, char *oldPath);
char	**sortFilesAndDir(char **args, int nbArgs);

#endif