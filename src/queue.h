#include "include.h"

struct queue_node {
	int data;
	struct queue_node* next;
	struct queue_node* prev;
};

typedef struct queue_node queue;

void queue_setup();
void queue_clean();
void queue_run();


void queue_init();
int queue_insert(int data);
int queue_pop();
int queue_find(int data);
void queue_show();
