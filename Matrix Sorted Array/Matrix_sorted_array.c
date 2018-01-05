#include<stdio.h>

void main()
{
   int temp,a[10][10],i,j,r,c;
   printf("Enter the number of rows:");
   scanf("%d",&r);
   printf("Enter the number of columns:");
   scanf("%d",&c);
   /*a=malloc(r*sizeof(int));
   for(i=0;i<c;i++)
   {
      *(a+i)=malloc(c*sizeof(int));
   }*/
   printf("Enter the array:\n");
   for(i=0;i<r;i++)
   {
      for(j=0;j<c;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   for(i=0;i<r*c;i++)
   {
      for(j=0;j<r*c-i-1;j++)
      {
         if(a[j/c][j%c]>=a[(j+1)/c][(j+1)%c])
         {
            temp=a[j/c][j%c];
            a[j/c][j%c]=a[(j+1)/c][(j+1)%c];
            a[(j+1)/c][(j+1)%c]=temp;
         }
      }
   }
   for(i=0;i<r;i++)
   {
      for(j=0;j<c;j++)
      {
         printf("%d ",a[i][j]);
      }
      printf("\n");
   }
   //free(a);
}
