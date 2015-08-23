#include "include.h"


typedef struct bintree{
		int data;
		struct bintree* l_child;
		struct bintree* r_child;

	} bin_tree;


void bintree_setup();
void bintree_clean();
void bintree_run();
void bintree_init();
void bintree_add_help(bin_tree* tmp, int data);

void bintree_add(int data);
void bintree_delete_for(bin_tree* tmp, int data);
void bintree_delete(bin_tree* tmp); // delete the tree from the tmp
void bintree_show(bin_tree* tmp);
void bintree_search(bin_tree* tmp,int data);


