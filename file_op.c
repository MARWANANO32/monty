#include "monty.h"
/**
 * parse_line - the function that separates each line
 * @buffer: the line for the file
 * @line_number: the line
 * @format: the storage
 * Return: 0 if it stack , 1 if otherwise
 */
int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		err(4);
	}
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
	{
		return (format);
	}
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	find_func(opcode, value, line_number, format);
	return (format);
}
/**
 * find_func - the function that approprite the function
 * @opcode: the opcode
 * @value: the argument of opcode
 * @format: the storage format
 * @ln: the line number
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i, flag;
	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	for (int i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number, format);
			return;
		}
	}
	err(3, line_number, opcode);
}
/**
 * call_func - the function that calls the required func
 * @func: the pointer
 * @op: the string
 * @val: the string
 * @ln: the line number
 * @format: the specifier
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int i, flag;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '_')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 1)
			add_to_queue(&node, ln);
		if (format == 0)
			func(&node, ln);
	}
	else
	{
		func(&top, ln);
	}


}
