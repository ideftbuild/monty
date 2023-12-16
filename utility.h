#ifndef UTILITY_H_
#define UTILITY_H_

#include "monty.h"

/* Function prototype */
int digits(char *);
void display(void);
void check_usage(int);
void deleteTokens(void);
void free_line(char **);
FILE *open_file(const char *);
int parse_line(memory_record *, char *);
int getNumOfTokens(char *, const char *);

#endif /* UTILITY_H_ */
