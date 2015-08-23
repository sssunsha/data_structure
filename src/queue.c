#include "queue.h"

queue* queue_top;
queue* queue_bottom; // top is the address of the queue top, and bottom is the bottom of the queue address
const int QUEUELEN = 10;
int queue_size = 0; // the current queue_size of the queue
int queue_pool[] = {1,2,3,4,5};


// the queue demo setup function
void queue_setup()
{
	puts("");
	puts(" wlecome to queue demo");
	puts("");
	queue_init();
	puts("after init the queue, now print the queue");
	queue_show();

}


// clean the queue and free the memory
void queue_clean()
{
	int j = 0;
	while(queue_size)
	{
		queue_pop(&j);
	}
}

// run the queue case
void queue_run()
{
	int index = 0;
	int data = 0;
	do{
		queue_run:
		puts("");
		puts("insert one new data to the queue ------------- 1");
		puts(" popup one data from the queue --------------- 2");
		puts("check one data is in the queue or not -------- 3");
		puts("show the queue all data ---------------------- 4");
		puts("exit ----------------------------------------- 0");
		scanf("%d", &index);
		switch(index)
		{
		case 0:
			return;
			break;
		case 1:
			puts("please input the new data you want to insert");
			scanf("%d", &data);
			if(queue_insert(data))
			{
				queue_show();
			}
			else
			{
				puts("the queue is full, can not insert now");
			}
			break;
		case 2:
			if(queue_pop(&data))
			{
				printf("the data popup is %d\n", data);
			}
			else
			{
				puts("the queue is empty, can not popup now");
			}
			break;
		case 3:
			puts("please input the data you want to check");
			scanf("%d", &data);
			if(queue_find(data))
			{
				printf("%d is in \n", data);
			}
			else
			{
				printf("%d is not in \n", data);
			}
			break;
		case 4:
			queue_show();
			break;
		default:
			puts("incorrect index is input please choose again");
			goto queue_run;
			break;
		}

	}while(index != 0);

}

// init the queue with some data
void queue_init()
{
	queue_top = NULL;
	queue_bottom = NULL;
	queue_size = 0;
	int i = 0;
	for(;i<5;i++)
	{
		queue_insert(queue_pool[i]);
	}
}


// insert the data into the queue
// @return: 1 = insert succeed, 0 =  the queue is full, can not insert anymore
int queue_insert(int data)
{
	if(queue_size <= QUEUELEN)
	{
		if(queue_top == NULL)
		{
			// there is no queue now
			queue* c = (queue*)malloc(sizeof(queue));
			c->data = data;
			queue_top = queue_bottom = c;
			queue_size++;
		}
		else
		{
			// there is queue now
			queue* c = (queue*)malloc(sizeof(queue));
			c->data = data;

			c->next = queue_top;
			queue_top->prev = c;
			queue_top = c;
			queue_size++;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

// popup one data from the queue
// @return: 1 =  popup succeed, 0 =  the queue is empty, can not popup anymore
// @param: *pdata = the popup data
int queue_pop(int* pdata)
{
	if(queue_size > 0)
	{
		*pdata = queue_bottom->data;
		queue* tmp = queue_bottom;
		queue_bottom = queue_bottom->prev;
		queue_size--;
		free(tmp);
		tmp = NULL;
		return 1;
	}
	else
	{
		// threre is no node in the queue
		return 0;
	}
}

// find the data is in the queue or not
// @return:1 = in the queue, 0 = not in the queue
int queue_find(int data)
{
	if(queue_size > 0)
	{
		int i = 0;
		queue* tmp = queue_top;
		while(i < queue_size)
		{
			if(tmp->data == data)
			{
				return 1; // find the data from the queue
			}
			tmp = tmp->next;
			i++;
		}
		// finish the looking for, can not find
		return 0;
	}
	else
	{
		return 0; // the queue is empty, so can not find the data
	}
}

void queue_show()
{
	int i = 0;
	if(queue_size > 0)
	{
		printf("queue -> ");
		queue* tmp = queue_top;
		while(i < queue_size){
			printf(" %d ", tmp->data);
			tmp = tmp->next;
			i++;
		}
		puts("");
	}
	else
	{
		// the queue is empty
		puts("");
		puts("queue is empty !!!");
		puts("");
	}
}
