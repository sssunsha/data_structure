#include "bintree.h"

bin_tree* tree = NULL;
const int COUNT = 10;
int pool[] =  {5, 2, 6, 7, 4, 3, 1, 9, 8, 0};
int search_result = 0;


// setup a bin tree
void bintree_setup()
{
	// init the tree
	puts("init the bin tree");
	bintree_init();

	// show the bin tree after init the tree
	puts("show the bin tree");
	bintree_show(tree);
	puts("");

}

void bintree_add_help(bin_tree* tmp, int data)
{
	if(tmp)
	{
		if(tmp->data >= data)
		{
			if(tmp->l_child)
			{
				bintree_add_help(tmp->l_child, data);
			}
			else
			{
				bin_tree* c = (bin_tree*)malloc(sizeof(bin_tree));
				c->data = data;
				c->l_child = NULL; // not have the left child now
				c->r_child = NULL; // not have the right child now
				tmp->l_child = c;
			}
		}
		else
		{
			if(tmp->r_child)
			{
				bintree_add_help(tmp->r_child, data);
			}
			else
			{
				bin_tree* c = (bin_tree*)malloc(sizeof(bin_tree));
				c->data = data;
				c->l_child = NULL; // not have the left child now
				c->r_child = NULL; // not have the right child now
				tmp->r_child = c;
			}
		}
	}
}

void bintree_init()
{
	bin_tree* tmp = tree;
	int i = 0;
	for(i = 0; i < COUNT; i++)
	{
		if(tmp)
		{
			bintree_add_help(tmp, pool[i]);
		}
		else
		{
			// now is a empty tree, so set the pool[i]'s data to the root
			bin_tree* c = (bin_tree*)malloc(sizeof(bin_tree));
			c->data = pool[i];
			c->l_child = NULL; // not have the left child now
			c->r_child = NULL; // not have the right child now
			tree = c; // this one is the tree's root
			tmp = tree;
		}
	}
}

void bintree_clean()
{
	// clean the tree
	puts("free the whole bin tree");
	bintree_delete(tree);
	puts("");
}

void bintree_run()
{
	puts("start to run the case for the bin tree");
	int data;
	int index;
	do{
		bintree_setup:
		puts("please try to choose the menu for what you want");
		puts("add new data ---------------------- 1");
		puts("delete data ----------------------- 2");
		puts("check data is in the tree or not -- 3");
		puts("exit ------------------------------ 0");
		scanf("%d", &index);
		puts("");
		switch(index)
		{
		case 0:
			break;
		case 1:
			puts("please input the data you want to add");
			scanf("%d", &data);
			bintree_add(data);
			bintree_show(tree);
			puts("");
			break;
		case 2:
			puts("please input the data you want to delete");
			scanf("%d", &data);
			bintree_delete_for(tree,data);
			bintree_show(tree);
			puts("");
			break;
		case 3:
			puts("please input the data you want to check is in or not");
			scanf("%d", &data);
			search_result = 0;
			bintree_search(tree, data);
			if(search_result)
			{
				printf("the data %d is in the tree\n", data);
			}
			else
			{
				printf("the data %d is not in the tree\n", data);
			}
			break;
		default:
			goto bintree_setup;
			break;

		}
	}while(index != 0);
}


void bintree_add(int data)
{
	bintree_add_help(tree, data);
}

void bintree_delete_for(bin_tree* tmp, int data)
{
	if(tmp->l_child)
		{
			bintree_delete_for(tmp->l_child,data);
		}

		if(tmp->r_child)
		{
			bintree_delete_for(tmp->r_child,data);
		}

		if(data == tmp->data)
		{
			if(tmp->l_child)
			{
				// has the left leaf
				free(tmp);
				tmp->l_child = tmp;
				tmp = NULL;
			}
			else if(tmp->r_child)
			{
				// has the right leaf
				free(tmp);
				tmp->r_child = tmp;
				tmp = NULL;
			}
			else
			{
				// self is the leaf
				// delete the tmp
				free(tmp);
				tmp = NULL;

			}
		}


}

void bintree_delete(bin_tree* tmp)
{
	if(tmp->l_child)
	{
		bintree_delete(tmp->l_child);
	}

	if(tmp->r_child)
	{
		bintree_delete(tmp->r_child);
	}

	free(tmp);
	tmp = NULL;

}


// 打印二叉树的逻辑是，先子后父，先左后右
void bintree_show(bin_tree* tmp)
{
	if(tmp->l_child)
	{
		bintree_show(tmp->l_child);
	}

	if(tmp->r_child)
	{
		bintree_show(tmp->r_child);
	}

	printf("  %d  ", tmp->data);
}


void bintree_search(bin_tree* tmp,int data)
{
	if(tmp->l_child)
	{
		bintree_search(tmp->l_child, data);
	}

	if(tmp->r_child)
	{
		bintree_search(tmp->r_child, data);
	}

	if(tmp->data == data)
		search_result = 1;
}
