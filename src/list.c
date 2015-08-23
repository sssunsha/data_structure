#include "list.h"

sin_node* list;

void list_setup(){
	list_single_setup();
	list_single_run();
}

void list_clean(){
	list_single_clean();
}


void list_single_setup(){
	// init the single list
	init_single_list();
}

void list_single_run(){
	puts("");
	puts("start to run the single list case.");
	puts("");
	int i = 0;
	int index, data;
	do{
		puts("chose with the menu for the operate you want");
		puts("insert at -------------------------- 1");
		puts("insert end ------------------------- 2");
		puts("delete at -------------------------- 3");
		puts("delete for ------------------------- 4");
		puts("print the whole list --------------- 5");
		puts("exit ------------------------------- 0");
		scanf("%d", &i);
		switch(i)
		{
		case 0:
			return;
			break;
		case 1:
			puts("please input the index you want to insert to the list for the data");
			scanf("%d", &index);
			printf("please input the data you want to insert to the list at %d\n", index);
			scanf("%d", &data);
			insert_single_node_at(data, index);
			show_single_node();
			break;
		case 2:
			puts("please input the data you want to insert to the list end");
			scanf("%d", &data);
			insert_single_node_end(data);
			show_single_node();
			break;
		case 3:
			puts("please input the index you want to delete the node of the list");
			scanf("%d", &index);
			delete_single_node_at(index);
			show_single_node();
			break;
		case 4:
			puts("please input the data for the note you want to delete for the list");
			scanf("%d", &data);
			delete_single_node_for(data);
			show_single_node();
			break;
		case 5:
			show_single_node();
			break;
		default:
			return;
			break;

		}
	}
	while(i);

}

void list_single_clean(){

	// free all the single list
	free_single_node(list);

}


// init a single list
void init_single_list()
{
	// init a single list
	list = (sin_node*)malloc(sizeof(sin_node));
	list->next = NULL;
	list->data = 0;

	// insert 10 data to the single list
	int i = 1;
	for(; i < 10; i++)
	{
		insert_single_node_end(i);
	}

}

// insert one new node with the data to the list
void insert_single_node_end(int data)
{
	sin_node* node = (sin_node*)malloc(sizeof(sin_node));
	sin_node* tmp = list;
	node->data = data;
	node->next = NULL;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

// insert one new node with the data to the list at the index
void insert_single_node_at(int data, int index)
{
	sin_node* node = (sin_node*)malloc(sizeof(sin_node));
	sin_node* tmp = list;
	sin_node* tmp2 = list;
	node->data = data;

	int i = 0;
	for(; i < index; i++)
	{
		if(tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		else
		{
			// the index is longer than the list, so can not insert the new data
			free(node);
			return;
		}

	}

	if(i == 0)
	{
		node->next = list;
		list = node;

	}
	else
	{
		tmp2->next = node;
		node->next = tmp;

	}

}

void delete_single_node_at(int index)
{
	printf("delete the node at %d of the single list\n", index);
	int i = 0;
	sin_node* tmp = list;
	sin_node* tmp2 = list;
	while(i < index)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		i++;
	}

	if(i == 0)
	{
		list = list->next;
		free(tmp);
	}
	else
	{
		tmp2->next = tmp->next;
		free(tmp);
	}

}

// delete the node of the single list which's data is == data given
void delete_single_node_for(int data)
{
	sin_node* tmp = list;
	sin_node* tmp2 = list;
	while(tmp)
	{
		if(tmp->data == data)
		{
			// find the data need to delete
			if(tmp ==  tmp2)
			{
				// the delete node is the first one
				list = tmp->next;
				free(tmp);
			}
			else
			{
				tmp2->next = tmp->next;
				free(tmp);
			}
//			return;
		}
		tmp2 = tmp;
		tmp =  tmp->next;
	}
}

void show_single_node()
{
	sin_node* tmp = list;
	printf(" %d ", tmp->data);
	while(tmp->next)
	{
		tmp = tmp->next;
		printf(" %d ", tmp->data);
	}

	puts("");
}

void free_single_node()
{
	sin_node* tmp;
	while(list->next)
	{
		tmp = list->next;
		free(list);
		list =  tmp;
	}
}

void init_double_list()
{

}


