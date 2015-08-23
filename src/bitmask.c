#include "bitmask.h"

void bitmask_setup()
{
	puts("");
	puts("");
	puts("introduce the bitmask(排序) menu and do the +,-,*,/ with bitmask");
	puts("");
	bitmask_setup:
	puts("clean a var （对一个数快速清零） ------------------ 1");
	puts(" get a var's center data(获取一个数的对应位) ------ 2");
	puts("+ ---------------------------------------------- 3");
	puts("- ---------------------------------------------- 4");
	puts("* ---------------------------------------------- 5");
	puts("/ ---------------------------------------------- 6");
	puts("please input the index:");
	int index = 0;
	int a, b, m;
	scanf("%d", &index);
	switch(index)
	{
	case 1:
		bitmask_clean_var();
		break;
	case 2:
		bitmask_get_value();
		break;
	case 3:
		puts("please input the two number you want to add:");
		printf("a = ");
		scanf("%d", &a);
		printf("\nb = ");
		scanf("%d", &b);
		puts("");
		m = bitmask_add(a, b);
		printf("%d + %d = %d\n",a, b, m);
		break;
	case 4:
		puts("please input the two number you want to subtract:");
		printf("a = ");
		scanf("%d", &a);
		printf("\nb = ");
		scanf("%d", &b);
		puts("");
		m = bitmask_subtract(a, b);
		printf("%d - %d = %d\n",a, b, m);
		break;
	case 5:
		puts("please input the two number you want to multiply:");
		printf("a = ");
		scanf("%d", &a);
		printf("\nb = ");
		scanf("%d", &b);
		puts("");
		m = bitmask_multiply(a, b);
		printf("%d * %d = %d\n",a, b, m);
		break;
	case 6:
		puts("please input the two number you want to divide:");
		printf("a = ");
		scanf("%d", &a);
		printf("\nb = ");
		scanf("%d", &b);
		puts("");
		m = bitmask_divide(a, b);
		printf("%d / %d = %d\n",a, b, m);
		break;
	default:
		puts("the index is incorrect, please choose again");
		goto bitmask_setup;
	}

}

// clean the value with bitmask
void bitmask_clean_var()
{
	int i = rand();
	printf("the random value is %d\n", i);
	puts("i = &0");
	i = i&0;
	printf("after clean the random value is %d\n", i);
}


// get the data with btimask
void bitmask_get_value()
{
	int i = rand();
	int index = 0;
	printf("the random value is %d\n", i);
	printf("please input the index you want to get (10 进制下) :");
	scanf("%d", &index);
	int j = 10, n;
	for(n=0; n < (index-1); n++)
	{
		j = (j<< 3) + 20;
	}
	i = i&(j-1);
	printf("the value is %d\n", i);
}

// do the add operate with bitmask
int bitmask_add(int a, int b){
	int n=a&b;
	 int m=a^b;
	 while(n)
	 {
	  int t_a=m;
	  int t_b=n<<1;
	  n=t_a&t_b;
	  m=t_a^t_b;
	 }
	 return m;
}


// do the subtract operate with bitmask
int bitmask_subtract(int a, int b){
	// subtract is similar with
	b = ~b;
	b = bitmask_add(b, 1);
	return bitmask_add(a, b);
}


// do the multiply operate with bitmask
int bitmask_multiply(int a, int b){
	int i = 1;
	int m = 0;
	int n = 0;
	while(b >= i){
		if((b & i) > 0)
		{
			m = bitmask_add(m, a << n);
		}
		n++;
		i = i << 1;
	}
	return m;
}

// do the divide operate with bitmask
int bitmask_divide(int a, int b){
	int m = 0;
	while(a >= b )
	{
		a = bitmask_subtract(a, b);
		m = bitmask_add(m , 1);
	}
	return m;
}
