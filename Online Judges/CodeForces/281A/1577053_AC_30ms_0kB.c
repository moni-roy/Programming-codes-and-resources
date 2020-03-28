#include<stdio.h>
#include<string.h>

int main()
{
char str[10000];
while(gets(str)!=NULL)
{
if(str[0]>='a'&&str[0]<='z')
{
str[0]=str[0]+'A'-'a';
}

puts(str);
}
return 0;
}
