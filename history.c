#include <stdio.h>
#define MAX_LIMIT 20
int main()
{
char str[MAX_LIMIT];
fgets(str, MAX_LIMIT, stdin);
printf("%s", str);
int c;
scanf("%d",&c);
return 0;
}
