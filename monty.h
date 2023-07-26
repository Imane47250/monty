#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Owned by: Imane & Fatima Zahra
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Owned by: Imane & Fatima Zahra
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* doubly linked list prototypes */
int add_end_node(stack_t **stack, int n);
void delete_end_node(stack_t **stack);
void free_dlist(stack_t **stack);

/* operations prototypes */
void _add(stack_t **stack, unsigned int line_num);
void _sub(stack_t **stack, unsigned int line_num);
void _mul(stack_t **stack, unsigned int line_num);
void _div(stack_t **stack, unsigned int line_num);
void _mod(stack_t **stack, unsigned int line_num);
int is_valid_integer(const char *n);


/* opcodes prototypes */
void (*find_opcode_func(char *token1))(stack_t **stack, unsigned int line_num);
void push(stack_t **h, unsigned int line_number, const char *n);
void pop(stack_t **h, unsigned int line_number);
void pint(stack_t **h, unsigned int line_number);
void pall(stack_t **h, unsigned int line_number);
void swap(stack_t **sw, unsigned int line_number);
void nop(stack_t **h, unsigned int line_number);
void pchar(stack_t **h, unsigned int line_number);
void pstr(stack_t **h, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);


#endif
