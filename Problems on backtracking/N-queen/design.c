void display(int **a,int n)
{
   int i,k,j;
   for(i=0;i<n;i++)
   {
      printf("\n ");
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
      printf("|");
   }
   printf("\n ---- ---- ---- ----\n\n");
}
