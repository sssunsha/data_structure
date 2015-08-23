#include "hashtable.h"

void hash_setup()
{
	char str[10];
	hash_setup:
	puts("");
	puts("please input a char* sentences");
	scanf("%s", str);
	if(*str == '0')
	{
		return;
	}
	else
	{
		printf("%s hash to %ud \n", str, hash(str));
		goto hash_setup;
	}

}

void hash_clean()
{

}

unsigned int hash(char *str)
{
    register unsigned int h;
    register unsigned char *p;

    for(h=0, p = (unsigned char *)str; *p ; p++)
        h = 31 * h + *p;

    return h;
}
