#include "stack.h"

stack* stack_top;
stack* stack_bottom; // top is the address of the stack top, and bottom is the bottom of the stack address
const int STACKLEN = 10;
int stack_size = 0; // the current stack_size of the stack
int stack_pool[] = {1,2,3,4,5};


// the stack demo setup function
void stack_setup()
{
	puts("");
	puts(" wlecome to stack demo");
	puts("");
	stack_init();
	puts("after init the stack, now print the stack");
	stack_show();

}


// clean the stack and free the memory
void stack_clean()
{
	int j = 0;
	while(stack_size)
	{
		stack_pop(&j);
	}
}

// run the stack case
void stack_run()
{
	int index = 0;
	int data = 0;
	do{
		stack_run:
		puts("");
		puts("insert one new data to the stack ------------- 1");
		puts(" popup one data from the stack --------------- 2");
		puts("check one data is in the stack or not -------- 3");
		puts("show the stack all data ---------------------- 4");
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
			if(stack_insert(data))
			{
				stack_show();
			}
			else
			{
				puts("the stack is full, can not insert now");
			}
			break;
		case 2:
			if(stack_pop(&data))
			{
				printf("the data popup is %d\n", data);
			}
			else
			{
				puts("the stack is empty, can not popup now");
			}
			break;
		case 3:
			puts("please input the data you want to check");
			scanf("%d", &data);
			if(stack_find(data))
			{
				printf("%d is in \n", data);
			}
			else
			{
				printf("%d is not in \n", data);
			}
			break;
		case 4:
			stack_show();
			break;
		default:
			puts("incorrect index is input please choose again");
			goto stack_run;
			break;
		}

	}while(index != 0);

}

// init the stack with some data
void stack_init()
{
	stack_top = NULL;
	stack_bottom = NULL;
	stack_size = 0;
	int i = 0;
	for(;i<5;i++)
	{
		stack_insert(stack_pool[i]);
	}
}


// insert the data into the stack
// @return: 1 = insert succeed, 0 =  the stack is full, can not insert anymore
int stack_insert(int data)
{
	if(stack_size <= STACKLEN)
	{
		if(stack_top == NULL)
		{
			// there is no stack now
			stack* c = (stack*)malloc(sizeof(stack));
			c->data = data;
			stack_top = stack_bottom = c;
			stack_size++;
		}
		else
		{
			// there is stack now
			stack* c = (stack*)malloc(sizeof(stack));
			c->data = data;

			c->next = stack_top;
			stack_top->prev = c;
			stack_top = c;
			stack_size++;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

// popup one data from the stack
// @return: 1 =  popup succeed, 0 =  the stack is empty, can not popup anymore
// @param: *pdata = the popup data
int stack_pop(int* pdata)
{
	if(stack_size > 0)
	{
		*pdata = stack_top->data;
		stack* tmp = stack_top;
		if(stack_size != 1) // if the stack_size is 1, there is no next now
		stack_top = stack_top->next;
		stack_top->prev = NULL;
		stack_size--;
		free(tmp);
		tmp=NULL;
		return 1;
	}
	else
	{
		// threre is no node in the stack
		return 0;
	}
}

// find the data is in the stack or not
// @return:1 = in the stack, 0 = not in the stack
int stack_find(int data)
{
	if(stack_size > 0)
	{
		int i = 0;
		stack* tmp = stack_top;
		while(i < stack_size)
		{
			if(tmp->data == data)
			{
				return 1; // find the data from the stack
			}
			tmp = tmp->next;
			i++;
		}
		// finish the looking for, can not find
		return 0;
	}
	else
	{
		return 0; // the stack is empty, so can not find the data
	}
}

void stack_show()
{
	int i = 0;
	if(stack_size > 0)
	{
		printf("stack -> ");
		stack* tmp = stack_top;
		while(i < stack_size){
			printf(" %d ", tmp->data);
			tmp = tmp->next;
			i++;
		}
		puts("");
	}
	else
	{
		// the stack is empty
		puts("");
		puts("stack is empty !!!");
		puts("");
	}
}
