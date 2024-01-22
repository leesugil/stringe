/* this is an improved version of getword shown in the book that only utilizes the standard C libraries */

#ifndef GETWORD_H
#define GETWORD_H

#include <ctype.h>
#include <stdio.h>

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getchar()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getchar())) {
			ungetc(*w, stdin);
			break;
		}
	*w = '\0';
	return word[0];
}

void testgetword()
{
	int maxchar = 100;
	char c, word[maxchar];
	while ((c = getword(word, maxchar)) != EOF)
		fprintf(stderr, "\"%s\"\n", word);
}

/* sgetword: get next word from string while reducing it */
int sgetword(char **s, char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = *(*s)++))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = *(*s)++)) {
			(*s)--;
			break;
		}
	*w = '\0';
	return word[0];
}

void testsgetword(char *s)
{
	int maxchar = 100;
	char c, word[maxchar];
	while ((c = sgetword(&s, word, maxchar)) != EOF && c != '\0')
		fprintf(stderr, "\"%s\"\n", word);
}

#endif	/* GETWORD_H */
