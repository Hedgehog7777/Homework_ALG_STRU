#include <stdio.h>

// Задание №1***************************************************************
void hfu(char * a)
{
 int b =0;
 int i =0;
 while(* a != 0)
 {
  b = b+ * a;
  a++;
  i++;
 }
 while(i != 0)
 {
  a--;
  i--;
 }
 printf("hfu(%s) = %d\n", a, b);
}



// Задание №2***************************************************************
#define n 5
#define m 3

void printarr(int * arr, int k, char * s)
{
 printf("%s[%d] = [", s, k);
 for (int i =0; i<k; i++)
 {
  if(i == k-1)
  {
   printf("%3d]\n", arr[i]);
  }
  else 
  {
    printf("%3d, ", arr[i]);
  }
 }
}
  
void gad(int * mon, int * kol, int size, int a)
{
  for (int i = 0; i < size; i++)
  { 
   printf("*kol=%d\n", *kol);
   printf("a=%d\n", a);
   while(*mon <= a)
   {
    a = a - * mon;
    *kol += 1;
   }
   mon++;
   kol++; 
  }
}
int main()
{
// Задание №1***************************************************************
char * a = "PROverka hfu";
hfu(a);
char * b = "proverka hfu";
hfu(b);

// Задание №2***************************************************************

int mon [n] = {50, 10, 5, 2, 1};
int kol [n] = {0};

printarr(mon, n , "mon");
printarr(kol, n , "kol");

gad(mon, kol, n, 98);

printarr(mon, n, "mon");
printarr(kol, n, "kol");


//_______________________________________________________________________
int mon2 [m] = {4, 3, 1,};
int kol2 [m] = {0};

printarr(mon2, m , "mon2");
printarr(kol2, m , "kol2");

gad(mon2, kol2, m, 15);

printarr(mon2, m, "mon2");
printarr(kol2, m, "kol2");


return 0;
}
