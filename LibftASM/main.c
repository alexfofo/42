/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:44:57 by afollin           #+#    #+#             */
/*   Updated: 2015/05/11 14:44:59 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>

#define YES "\033[1;32mYES\033[0m"
#define NO "\033[1;31mNO\033[0m"

int ft_toupper(int);
int ft_tolower(int);
int ft_isalpha(int);
int ft_isdigit(int);
int ft_isalnum(int);
int ft_isascii(int);
int ft_isprint(int);
void ft_bzero(char *, int);
char *ft_strcat(char *, char *);
int ft_strlen(char *);
int ft_puts(char *);
void *ft_memcpy(void *dst, void *src, size_t n);
void *ft_memset(void *dst, int c, size_t n);
char *ft_strdup(char *s);
void ft_cat(int fd);

int ft_iscntrl(int);
int ft_islower(int);
int ft_ispunct(int);
int ft_isspace(int);
int ft_isupper(int);



int		main(int argc, char **argv)
{
	int		i;
	char	*test;
	char	*ret_from_cat;

if (argc != 3){

	printf("\033[7;37m[DEBUT] ft_toupper\033[0m\n");
	printf("%c\n", ft_toupper(42));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('z'));
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('Z'));



	printf("\n\033[7;37m[DEBUT] ft_tolower\033[0m\n");
	printf("%c\n", ft_tolower(42));
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('z'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('Z'));



	printf("\n\033[7;37m[DEBUT] ft_isalpha\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isalpha(i) ? YES : NO, isalpha(i) ? YES : NO);



	printf("\n\033[7;37m[DEBUT] ft_isdigit\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isdigit(i) ? YES : NO, isdigit(i) ? YES : NO);



	printf("\n\033[7;37m[DEBUT] ft_isalnum\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isalnum(i) ? YES : NO, isalnum(i) ? YES : NO);



	printf("\n\033[7;37m[DEBUT] ft_isascii\033[0m\n");
	i = -2;
	while (++i < 129)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isascii(i) ? YES : NO, isascii(i) ? YES : NO);



	printf("\n\033[7;37m[DEBUT] ft_isprint\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isprint(i) ? YES : NO, isprint(i) ? YES : NO);

	printf("\n\033[7;37m[DEBUT] ft_bzero\033[0m\n");
	test = (char *)malloc(sizeof(char) * 10);
	bzero(test, 10);
	strcat(test, "bonjour !");
	printf("test: %s\n", test);
	ft_bzero(test, 10);
	printf("test: %s\n", test);
	i = -1;
	printf("test: ");
	while (++i < 10)
		printf("%s", !test[i] ? "0" : "ceci ne s'affiche jamais");
	printf("\n");

	printf("\n\033[7;37m[DEBUT] ft_strcat\033[0m\n");
	printf("test: %s\n", test);
	ret_from_cat = ft_strcat(test, "assassins");
	printf("test: %s\n", test);
	printf("ret_from_cat: %s\n", ret_from_cat);
	bzero(test, 10);
	ft_strcat(test, "lol ");
	ft_strcat(test, "mdr");
	printf("test: %s\n", test);


	printf("\n\033[7;37m[DEBUT] ft_strlen\033[0m\n");
	printf("ft_strlen('coucou') = %d\n", ft_strlen("coucou"));
	printf("ft_strlen('') = %d\n", ft_strlen(""));


	printf("\n\033[7;37m[DEBUT] ft_strputs\033[0m\n");
	ft_puts("Hola seniorita hey");
	ft_puts(test);
	ft_puts("");
	puts("Hola seniorita hey");
	puts(test);
	puts("");

char *str2;
	printf("\n\033[7;37m[DEBUT] ft_memcpy\033[0m\n");
	free(test);
	test = NULL;
	test = (char *)malloc(sizeof(char) * 11);
	ft_bzero(test, 11);
	str2 = (char *)malloc(sizeof(char) * 10);
	bzero(str2, 10);
	strcat(test, "Hola mundo");
	strcat(str2, "goodbye");
	printf("str1: %s\n", test);
	printf("str2: %s\n", str2);
	ft_memcpy(test, str2, 7);
	printf("after memcpy, str1: %s\n", test);



	printf("\n\033[7;37m[DEBUT] ft_memset\033[0m\n");
	free(test);
	test = NULL;
	test = (char *)malloc(sizeof(char) * 11);
	ft_bzero(test, 11);
	strcat(test, "Hola");
	printf("str: %s\n", test);
	ft_memset(test, 'x', 9);
	printf("after memset, str: %s\n", test);


char *dollar;
	printf("\n\033[7;37m[DEBUT] ft_strdup\033[0m\n");
	free(test);
	test = NULL;
	test = (char *)malloc(sizeof(char) * 11);
	ft_bzero(test, 11);
	strcat(test, "LOL");
	printf("str: %s\n", test);
	dollar = ft_strdup(test);
	printf("dollar: %s\n", dollar);

int bb;
bb = 0;
	printf("\n\033[7;37m[DEBUT] ft_cat\033[0m\n");
	if (argc == 2)
	{
		i = open(argv[1], O_RDONLY);
		if (i != -1)
			ft_cat(i);
		else
			printf("Invalid file\n");
	}
	else
		ft_cat(0);
	}
else
{
	printf("\n-------------------- BONUS ----------------------------\n");
	printf("\n\033[7;37m[DEBUT] ft_iscntrl\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_iscntrl(i) ? YES : NO, iscntrl(i) ? YES : NO);

	printf("\n\033[7;37m[DEBUT] ft_islower\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_islower(i) ? YES : NO, islower(i) ? YES : NO);

	printf("\n\033[7;37m[DEBUT] ft_ispunct\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_ispunct(i) ? YES : NO, ispunct(i) ? YES : NO);

	printf("\n\033[7;37m[DEBUT] ft_isspace\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isspace(i) ? YES : NO, isspace(i) ? YES : NO);

	printf("\n\033[7;37m[DEBUT] ft_isupper\033[0m\n");
	i = -1;
	while (++i < 128)
		printf("%3d = %s\t(should be: %s)\n", i, ft_isupper(i) ? YES : NO, isupper(i) ? YES : NO);
}

	return (0);
}
