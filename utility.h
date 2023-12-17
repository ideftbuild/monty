#ifndef UTILITY_H_
#define UTILITY_H_

#define MIN_NODE 2

#include "monty.h"

/* Function prototype */
int getMin(void);
int digits(char *);
void check_usage(int);
int getNodeCount(void);
void deleteTokens(void);
void free_line(char **);
FILE *open_file(const char *);
int parse_line(memory_record *, char *);
int getNumOfTokens(char *, const char *);

#endif /* UTILITY_H_ */
