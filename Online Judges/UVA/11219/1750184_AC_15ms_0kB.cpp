
#include<stdio.h>
int main()
{
    int c1,c2,c3,b1,k=1,b2,b3,i,T;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d/%d/%d",&c1,&c2,&c3);
        scanf("%d/%d/%d",&b1,&b2,&b3);
        if(c1-b1<0)
        {
            if((c2-1)-b2<0)
            {
                if((c3-1)-b3<0)
                {
                    printf("Case #%d: Invalid birth date\n",k++);
                }
                else if(((c3-1)-b3)==0)
                {

                        printf("Case #%d: 0\n",k++);
                  }
                   else if(((c3-1)-b3)>130)
                {

                        printf("Case #%d: Check birth date\n",k++);
                  }
                  else{


                        printf("Case #%d: %d\n",k++,((c3-1)-b3));
                  }

           }
          else if((c2-1)-b2>=0)
            {
                if(c3-b3<0)
                {
                    printf("Case #%d: Invalid birth date\n",k++);
                }
                else if(c3-b3==0)
                {

                        printf("Case #%d: 0\n",k++);
                  }
                   else if(c3-b3>130)
                {

                        printf("Case #%d: Check birth date\n",k++);
                  }
                  else{


                        printf("Case #%d: %d\n",k++,(c3-b3));
                  }

           }
      }
       else
        {
            if(c2-b2<0)
            {
                if((c3-1)-b3<0)
                {
                    printf("Case #%d: Invalid birth date\n",k++);
                }
                else if(((c3-1)-b3)==0)
                {

                        printf("Case #%d: 0\n",k++);
                  }
                   else if(((c3-1)-b3)>130)
                {

                        printf("Case #%d: Check birth date\n",k++);
                  }
                  else{


                        printf("Case #%d: %d\n",k++,((c3-1)-b3));
                  }

           }
          else if(c2-b2>=0)
            {
                if(c3-b3<0)
                {
                    printf("Case #%d: Invalid birth date\n",k++);
                }
                else if(c3-b3==0)
                {

                        printf("Case #%d: 0\n",k++);
                  }
                   else if(c3-b3>130)
                {

                        printf("Case #%d: Check birth date\n",k++);
                  }
                  else{


                        printf("Case #%d: %d\n",k++,c3-b3);
                  }

           }
      }
    }
    return 0;
}
