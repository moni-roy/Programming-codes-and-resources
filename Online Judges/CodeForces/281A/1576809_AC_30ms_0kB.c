#include<stdio.h>
#include<string.h>

int main()
{
char str[10000];
while(gets(str)!=NULL)
{
str[0]=toupper(str[0]);

puts(str);
}
return 0;
}
