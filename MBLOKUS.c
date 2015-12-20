#include <stdio.h>


/*
[Description]
 run in 10 sec
 limited in 64MB

*/


int t
int i;
char a[102];

int main(void)
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",a);
		for(i=0;a[i];++i)if(!(i&1))putchar(a[i]);
		for(i=0;a[i];++i)if( (i&1))putchar(a[i]);
		putchar('\n');
	}
	return 0;
}