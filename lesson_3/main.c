#include <stdio.h>

int prov(int a, int b)
{
 b = 0; 
 for (int i=2; i < a; i++)
  {
   if(a % i == 0)
   {
    b += 1;
    i = a;
   }
  }
 return b;
}

int main()
{
 int a;
 int b;
 printf("Enter the number ");
 scanf("%d", &a);
 printf("\n");
 if(prov(a, b) != 0)
  {
   printf("The number %d is not prime \n", a);
  }
  else
  {
   printf("The number %d is prime \n", a);
  }
 return 0;
}
