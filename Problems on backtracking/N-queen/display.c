void display(int **a,int n,int c)
{
   int i,k,j;
   printf("Solution %d:\n",c);
   for(i=0;i<n;i++)
   {
      for(k=0;k<n;k++)
      printf("---- ");
      printf("\n");
      for(j=0;j<n;j++)
      {
         if(a[i][j]==1)
         printf("| Q  ");
         else
            printf("|    ");
      }
      printf("\b|\n");
   }
   for(k=0;k<n;k++)
   printf("---- ");
   printf("\n");
}
