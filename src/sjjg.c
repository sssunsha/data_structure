
#include "sjjg.h"

void setup(){
	// introduce the mian menu of the data structure and algorithms
	puts("introduce the mian menu of the data structure and algorithms");

	main_setup:

	puts("");
	puts("Sorting(排序) --------------------- 1");
	puts("Bitmask(位运算) ------------------- 2");
	puts("Linked List(链表) ----------------- 3");
	puts("Hash Table(哈希表) ---------------- 4");
	puts("Binary tree(二叉数) --------------- 5");
	puts("stack (栈) ------------------------ 6");
	puts("queue (队列) ---------------------- 7");
	puts("");
	puts("please input the index you want to go[1-7]");

	int index = 0;
	scanf("%d", &index);
	switch(index)
	{
	case 1:
		puts("go to Sorting part");
		sort_setup();
		sort_clean();
		break;
	case 2:
		puts("go to  Bitmask part");
		bitmask_setup();
		bitmask_setup();
		break;
	case 3:
		puts("go to Linked List part");
		list_setup();
		list_clean();
		break;
	case 4:
		puts("go to Hash Table part");
		hash_setup();
		hash_clean();
		break;
	case 5:
		puts("go to Binary Heap part");
		bintree_setup();
		bintree_run();
		bintree_clean();
		break;
	case 6:
		puts("go to stack part");
		stack_setup();
		stack_run();
		stack_clean();
		break;
	case 7:
		puts("go to queue part");
		queue_setup();
		queue_run();
		queue_clean();
		break;
	default:
		puts("incorrect index you chosen, please chose again");
		goto main_setup;
		break;
	}

	clean();

}

void clean(){

}


int main(void) {
	puts("");
	puts("");
	puts("------------------------------------------------");
	puts("本例子主要演示各种数据结构的相关的代码范例和相应的算法演示");
	puts("这里的参考主要有 严蔚敏版本的数据结构 和这个不错的数据结构介绍网站：http://visualgo.net/");
	puts("------------------------------------------------");
	puts("");
	puts("");

	setup();
	return EXIT_SUCCESS;
}
