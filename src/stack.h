#include "include.h"

struct stack_node {
	int data;
	struct stack_node* next;
	struct stack_node* prev;
};

typedef struct stack_node stack;

void stack_setup();
void stack_clean();
void stack_run();


void stack_init();
int stack_insert(int data);
int stack_pop();
int stack_find(int data);
void stack_show();
