#include<stdio.h>
#include<string.h>

char buffer[10000];

struct fibbonacci{
	char fibb[9900];
} nth[9900];

void reverse(char string[])
{
	int x,y;
	char temp;
	for(x=0,y=(strlen(string)-1);x<y;x++,y--)
	{
		temp=string[x];
		string[x]=string[y];
		string[y]=temp;
	}

	return;
}
void string_add(char a[] , char b[],int n)
{
	int i,sum,len;

	if(strlen(a)>strlen(b))
	{
		len=strlen(a);
	}
	else len=strlen(b);

	reverse(a);
	reverse(b);
    int	carry=0;

	for(i=0;i<len;i++)
	{
		if(i>=strlen(a))
			{
				a[i]='0';
			}
			if(i>=strlen(b))
			{
				b[i]='0';
			}

		sum=a[i]+b[i]-2*('0')+carry;
		buffer[i]=(sum%10)+'0';

		carry=0;
		if(sum>9)
		{
			carry=1;
		}
	}

	if(carry==1)
	{
		buffer[i]=(1%10)+'0';
	}
	reverse(buffer);

	strcpy(nth[n].fibb,buffer);
}

int main()
{
	int z,y,used[9900]={0};
    char A[9900]={0},B[9900]={0},D[]={'0','\0'},E[]={'1','\0'};

    while(scanf("%d",&z)!=EOF)
    {

        used[0]=2;
        used[1]=2;
        strcpy(nth[0].fibb,D);
        strcpy(nth[1].fibb,E);

        if(z==0)
        {
            printf("The Fibonacci number for %d is 0\n",z);
        }
        if(z==1)
        {
            printf("The Fibonacci number for %d is 1\n",z);
        }
        if(z==2)
        {
            printf("The Fibonacci number for %d is 1\n",z);
        }

    else if(z>2)
        {
            if(strlen(nth[z].fibb)>0)
            {
                goto skip;
            }
            for(y=2;y<=z;y++)
            {
                if(!used[y])
                    {
                    strcpy(A,nth[y-1].fibb);
                    strcpy(B,nth[y-2].fibb);

                    string_add(A,B,y);
                    }
                used[y]=2;
            }
            skip:;
            printf("The Fibonacci number for %d is %s\n",z,nth[z].fibb);
        }
    }

	return 0;
}
