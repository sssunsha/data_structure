#include "sorting.h"

void sort_clean(){

}

int array[10] = {12, -12, 0, 356, 1, 23, 987, 1245, 765, -98};

void sort_setup(){
	puts("");
	puts("");
	puts("introduce the sorting(排序) menu of the data structure and algorithms");
	puts("");
	sort_setup:
	puts("insert(插入排序) -------------------- 1");
	puts("bubble(冒泡排序) -------------------- 2");
	puts("select(选择排序) -------------------- 3");
	puts("shell(希尔排序) --------------------- 4");
	puts("quick(快速排序) --------------------- 5");
	puts("heap(堆排序) ------------------------ 6");
	puts("");
	puts("please input the index you want to go[1-4]");

	int index = 0;
	scanf("%d", &index);
	switch(index){
	case 1:
		puts("go to insert sort(插入排序)");
		before_sort();
		sort_insert();
		after_sort("insert sort(插入排序)");
		break;
	case 2:
		puts("go to bubble sort(冒泡排序)");
		before_sort();
		sort_bubble();
		after_sort("bubble sort(冒泡排序)");
		break;
	case 3:
		puts("go to select sort(选择排序)");
		before_sort();
		sort_select();
		after_sort("select sort(选择排序)");
		break;
	case 4:
//		puts("go to select sort(希尔排序)");
//		before_sort();
//		sort_shell();
//		after_sort("select sort(希尔排序)");
		puts("shell sort is to be continued ...");
		break;
	case 5:
		puts("go to select sort(快速排序)");
		before_sort();
		sort_quick();
		after_sort("select sort(快速排序)");
		break;
	case 6:
//		puts("go to select sort(堆排序)");
//		before_sort();
//		sort_heap();
//		after_sort("select sort(堆排序)");
		puts("heap sort is to be continued ...");
		break;

	default:
		puts("incorrect index you chosen, please chose again");
		goto sort_setup;
		break;
	}
}

void before_sort(){
	array[0] = 12;
	array[1] =  -12;
	array[2] = 0;
	array[3] = 356;
	array[4] = 1;
	array[5] = 23;
	array[6] = 987;
	array[7] = 1245;
	array[8] = 765;
	array[9] = -98;
	int i = 0;
	puts("");
	puts("the old array is:");
	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	puts("");
}


void after_sort(char* sort_name){
	int i = 0;
	puts("");
	printf("after %s from small to big...\n", sort_name);
		for(i = 0; i < 10; i++)
			printf("%d ", array[i]);
	puts("");
}
// 冒泡排序
/*
 * 算法思想简单描述：
在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒。即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。
下面是一种改进的冒泡算法，它记录了每一遍扫描后最后下沉数的位置k，这样可以减少外层循环扫描的次数。
冒泡排序是稳定的。算法时间复杂度O(n2)--[n的平方]
 */
void sort_bubble(){
	int i = 0, j = 0;
	// bubble sort
	int Count = 10;
	 int tmp;
	for(i=1;i<Count;i++)
	       {
	         for(j=Count-1;j>=i;j--)
	                {
	                  if(array[j]<array[j-1])
	                            {
	                              tmp = array[j-1];
	                              array[j-1] = array[j];
	                              array[j] = tmp;
	                            }
	                }
	       }

}

// 选择排序
/*
 * 算法思想简单描述：
在要排序的一组数中，选出最小的一个数与第一个位置的数交换；然后在剩下的数当中再找最小的与第二个位置的数交换，如此循环到倒数第二个数和最后一个数比较为止。
选择排序是不稳定的。算法复杂度O(n2)--[n的平方]
 */

void sort_select(){
	 int tmp;
	int iPos;
	int Count = 10;
	int i, j;
	for(i=0;i<Count-1;i++)
	{
	 tmp = array[i];
	 iPos = i;
	 for(j=i+1;j<Count;j++)
	 {
	  if(array[j]<tmp)
	  {
	   tmp = array[j];
	   iPos = j;
	  }
	 }
	 array[iPos] = array[i];
	  array[i] = tmp;
	  }
}

// 插入排序
/*在要排序的一组数中，假设前面(n-1) [n>=2] 个数已经是排好顺序的，现在要把第n个数插到前面的有序数中，使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。
直接插入排序是稳定的。算法时间复杂度O(n2)--[n的平方]
 *
 */
void sort_insert(){
		int i,j;
	    int temp;
		int Count = 10;
	    for (i=1; i<Count; i++) //
	    {
	        temp = array[i];
	        for (j=i-1; j>=0; j--)
	        {
	            if (temp > array[j])  //如果插入的值大于某个值，则退出循环
	            break;

	            array[j+1] = array[j];

	        }
	        array[j+1] = temp;
	    }
	}

// 希尔排序
/*
 *
 */
void sort_shell(){

}

// 快速排序
/*
 *快 速排序是对冒泡排序的一种本质改进。它的基本思想是通过一趟扫描后，使得排序序列的长度能大幅度地减少。在冒泡排序中，一次扫描只能确保最大数值的数移到 正确位置，而待排序序列的长度可能只减少1。快速排序通过一趟扫描，就能确保某个数（以它为基准点吧）的左边各数都比它小，右边各数都比它大。然后又用同 样的方法处理它左右两边的数，直到基准点的左右只有一个元素为止。它是由C.A.R.Hoare于1962年提出的。
显然快速排序可以用递归实现，当然也可以用栈化解递归实现。下面的函数是用递归实现的，有兴趣的朋友可以改成非递归的。
快速排序是不稳定的。最理想情况算法时间复杂度O(nlog2n)，最坏O(n2)
 */

void sort_quick_run(int* pData,int left,int right)
{
int i,j;
int middle,iTemp;
i = left;
j = right;
middle = pData[(left+right)/2]; //求中间值
do{
       while((pData[i]<middle) && (i<right))//从左扫描大于中值的数
                      i++;
       while((pData[j]>middle) && (j>left))//从右扫描大于中值的数
                      j--;
       if(i<=j)//找到了一对值
                     {
                      //交换
                       iTemp = pData[i];
                       pData[i] = pData[j];
                       pData[j] = iTemp;
                       i++;
                       j--;
                     }
}while(i<=j);//如果两边扫描的下标交错，就停止（完成一次）
//当左边部分有值(left<j)，递归左半边
if(left<j)
	sort_quick_run(pData,left,j);
//当右边部分有值(right>i)，递归右半边
if(right>i)
	sort_quick_run(pData,i,right);
}

void sort_quick(){
	int Count = 10;
	sort_quick_run(array,0,Count-1);
}


// 堆排序
/*
 * 堆排序是一种树形选择排序，是对直接选择排序的有效改进。
堆的定义如下：具有n个元素的序列（h1,h2,...,hn),当且仅当满足（hi>=h2i,hi>=2i+1）或（hi<=h2i,hi<=2i+1）(i=1,2,...,n/2)时称之为堆。在这里只讨论满足前者条件的堆。
由堆的定义可以看出，堆顶元素（即第一个元素）必为最大项。完全二叉树可以很直观地表示堆的结构。堆顶为根，其它为左子树、右子树。
初始时把要排序的数的序列看作是一棵顺序存储的二叉树，调整它们的存储顺序，使之成为一个堆，这时堆的根节点的数最大。然后将根节点与堆的最后一个节点交换。然后对前面(n-1)个数重新调整使之成为堆。依此类推，直到只有两个节点的堆，并对它们作交换，最后得到有n个节点的有序序列。
从算法描述来看，堆排序需要两个过程，一是建立堆，二是堆顶与堆的最后一个元素交换位置。所以堆排序有两个函数组成。一是建堆的渗透函数，二是反复调用渗透函数实现排序的函数。
堆排序是不稳定的。算法时间复杂度O(nlog2n)。
 */
void sort_heap(){

}

