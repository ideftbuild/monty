#ifndef MONT_H
#define MONT_H

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct store - Stores data in the members
 *
 * @tokens: Stores tokenized line from file
 * @head: The first node in the list
 * @tail: The last node in the list
 *
 * Description: Stores data initialized from the program inside
 * the members listed below
 */
typedef struct store
{
	char **tokens;

	/* first and last node in the list */
	stack_t *tail;
	stack_t *head;
} store;
extern store reference;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct addresses - Stores allocated memory address
 *
 * @file: An open file
 * @stack: Reference to the pointer to the first node in the list
 * @mapped: Address of the mapped structure
 * @line: Text from the file
 *
 * Description: Stores memory address that was allocated during the program
 */
typedef struct addresses
{
	FILE *file;
	stack_t **stack;
	instruction_t *mapped;
	char *line;

} memory_record;

/* Alias */
typedef unsigned int u_int;
typedef void (*Op_func)(stack_t **, u_int);

/* Function Protypes */
void add(stack_t **, u_int);
void nop(stack_t **, u_int);
void mul(stack_t **, u_int);
void sub(stack_t **, u_int);
void mod(stack_t **, u_int);
void pop(stack_t **, u_int);
void pint(stack_t **, u_int);
void _div(stack_t **, u_int);
void swap(stack_t **, u_int);
void rotr(stack_t **, u_int);
void pstr(stack_t **, u_int);
void rotl(stack_t **, u_int);
void pchar(stack_t **, u_int);
void delete_stack(stack_t **);
void comment(stack_t **, u_int);
void free_records(memory_record *);
void interpret(FILE *, stack_t **);
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pop_error(memory_record*, u_int);
void mod_error(memory_record *, u_int);
void mul_error(memory_record *, u_int);
void sub_error(memory_record *, u_int);
void add_error(memory_record *, u_int);
void div_error(memory_record *, u_int);
void push_error(memory_record *, u_int);
void pint_error(memory_record *, u_int);
void swap_error(memory_record *, u_int );
void pchar_error(memory_record *, u_int);
void handle_errors(memory_record *, u_int);
instruction_t *create_map_structure(FILE *);
int check_instruction(Op_func, char *, u_int);
void freeMem(FILE *, instruction_t *, char *);
Op_func get_operation(const char *, instruction_t *);
void initialize_record(memory_record *, stack_t **, char *);

#endif /* MONT_H */
