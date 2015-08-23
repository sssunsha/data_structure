#include "include.h"

// 单向链表
	struct single_node{
		int data;
		struct single_node* next;
	};

// 双向链表
	struct double_node{
		int data;
		struct double_node* next;
		struct double_node* pre;

	};

typedef struct dobule_node dou_node;
typedef struct single_node sin_node;

void list_setup();
void list_clean();

void list_single_setup();
void list_single_clean();
void list_single_run();

void init_single_list();
void insert_single_node_end(int data);
void insert_single_node_at(int data, int index);
void delete_single_node_at(int index);
void delete_single_node_for(int data);
void show_single_node();
void free_single_node();


void init_double_list();
