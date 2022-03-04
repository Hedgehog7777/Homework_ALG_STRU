#include <stdio.h>
#include <stdlib.h>

// Задание №1***************************************************************

#define KEY 17

void zaces(unsigned char * a, int k)
{
 int i =0;
 while(a[i] != 0)
 {
  int b = 0;
  //printf("b = %d\n", b);
  b = a[i] + k;
  // printf("b = %d\n", b);
  if(b > 126)
  {
  a[i] = b - 256;
  }
  else 
  {
   a[i] = b;
  }
  i++;
 }
}

void deces(unsigned char * a, int k)
{
 int i = 0;
 while(a[i] != 0)
 {
  int b = 0;
  //printf("b = %d\n", b);
  b = a[i] - k;
  // printf("b = %d\n", b);
  if(b >= 0)
  {
   a[i] = b;
  }
  else 
  {
   a[i] = 256 - b;
  }
  i++;
 }
}

// Задание №2***************************************************************

#define KEY2 4

void zashi(char *a, int k)
{
 int i = 0;
 while(*a != 0)
 {
  i++;
  a++;
 }
 a -= i;
 int q = 0;
 if(i%k == 0)
 {
  q = i/k;
 }
 else 
 {
  q = i/k +1;
 }
 char* b =(char*) malloc(q*k * sizeof(char));
 int n = 0;
 for (int j = 0; j<q; j++)
 {
  for (int l = 0; l<k; l++)
  {
   if (n < i)
   {
    *b = *a;
    a++;
    b++;
    n++;
   }
   else 
   {
    *b = 'X';
    b++;
   }
  }
 }
 b -= q*k;
 a -= i;
 for (int j = 0; j<q; j++)
 {
  for (int l = 0; l<k; l++)
  {
   *a =*(b + k*l + j);
   a++;
  }
 }
 free(b);
}


void deshi(char *a, int k)
{
 int i = 0;
 while(*a != 0)
 {
  i++;
  a++;
 }
 a -= i;
 int q = 0;
 q = i/k;
 char* b =(char*) malloc(q*k * sizeof(char));
 int n = 0;
 for (int j = 0; j<q; j++)
 {
  for (int l = 0; l<k; l++)
  {
   if (n < i)
   {
    *b = *a;
    a++;
    b++;
    n++;
   }
   else 
   {
    *b = 'X';
    b++;
   }
  }
 }
 b -= q*k;
 a -= i;
 for (int j = 0; j<q; j++)
 {
  for (int l = 0; l<k; l++)
  {
   *a =*(b + k*l + j);
   a++;
  }
 }
 free(b);
}


int main()
{

 // Задание №1***************************************************************
 
 char masseg[255] = {"Hello world!!!"};
 printf("masseg: %s\n", masseg);
 
 char masseg2[255] = {"This is a secret message2"};
 printf("masseg2: %s\n", masseg);
 printf("\n");

 zaces(masseg, KEY);
 printf("Caesar's cipher masseg :\t %s\n", masseg);
 
 deces(masseg, KEY);
 printf("Caesar deciphering masseg :\t %s\n", masseg);
 printf("\n");
 
 zaces(masseg2, KEY);
 printf("Caesar's cipher masseg2 :\t %s\n", masseg2);
 
 deces(masseg2, KEY);
 printf("Caesar deciphering masseg2 :\t %s\n", masseg2);
  printf("\n");
 
 // Задание №2***************************************************************
 
 zashi(masseg, KEY2);
 printf("Permutation cipher masseg :\t\t %s\n", masseg);

 deshi(masseg, KEY2);
 printf("Deciphering by permutation masseg :\t %s\n", masseg);
 printf("\n");
 
 zashi(masseg2, KEY2);
 printf("Permutation cipher masseg2 :\t\t %s\n", masseg2);

 deshi(masseg2, KEY2);
 printf("Deciphering by permutation masseg2 :\t %s\n", masseg2);
 printf("\n");
 
 return 0;
}
