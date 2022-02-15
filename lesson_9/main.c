#include <stdio.h>

//Задание №1**************************************************
#define T int
#define SIZEX 5
#define SIZEY 2

T que[SIZEY][SIZEX];
unsigned int items = 0;
 
void init()
{ 
 for (int i=0; i<SIZEX; i++)
 {
  que[1][i] = 0;
 }
}

void ins(int data, unsigned int prior)
{
 if (prior == 0)
 {
  printf(" 0  is not a priority!!!\n");
 }
 if (items < SIZEX)
 {
  que[0][items] = data;
  que[1][items] = prior;
  items++;
 }
 else 
 { 
  printf("Queue is full!!!\n");
 }
}

int rem()
{
 unsigned int a =0;
 unsigned int indx =0;
 for (int i=items; i >= 0; i--)
 {
  if (que[1][i] >= a)
  {
   a = que[1][i];
   indx = i;
  }
 }
 a = que[0][indx];
 items--;
 for(int i=indx; i <= (items); i++)
 {
  que[0][indx] = que[0][indx+1];
  que[1][indx] = que[1][indx+1];
 }
 que[0][items] = 0;
 que[1][items] = 0;
 return a;
}

void printar(int arr[][SIZEX])
{
 for(int i=0; i<SIZEY; i++)
 {
  for(int j=0; j<SIZEX; j++)
  {
   printf("% 5d", arr[i][j]);
  }
  printf("\n");
 }
 printf("\n");
}

//Задание №2**************************************************

#define I unsigned int
#define SIZE 100

int curs = -1;
I st[SIZE];

int push(I dat)
{
 if (curs < SIZE-1)
 {
  st[++curs]=dat;
  return 0;
 }
 else
 {
  printf("Stack overflow \n");
  return -1; 
 }
}

I pop()
{
 if (curs > -1)
 {
  return st[curs--];
 }
 else
 {
  printf("Stack is empty \n");
  return -1;
 }
}

unsigned long long int perevod(I x)
{
 int n = 0;
 while (x > 0)
 {
  if (x==1)
  {
   int y = push(1);
   //printf("st[ %d ] = %d\n", curs, st[curs]);
   if (y!=0)
   {
    return -1;
    break;
   }
   else
   {
    n++;
    x=0;
   } 
  }
  else
  {
   int y = push(x%2);
   //printf("st[ %d ] = %d\n", curs, st[curs]);
   if (y!=0)
   {
    return -1;
    break;
   }
   else
   {
    x=x/2;
    n++;
   } 
  }
 }
 unsigned long long int a = 0;
 while (n > 0)
 {
  unsigned long long int b = pop();
  //printf("st[ %d ] = %d\n", curs, st[curs]);
  for (unsigned long long int i = 1; i < n; i++)
  {
   b *= 10;
  }
  a = a + b;
  //printf("a = %lld\n", a);
  n--;
 }
 return a;
}

int main ()
{
//Задание №1**************************************************

init();
printar(que);

ins(12, 1);
printar(que);

ins(124, 33);
printar(que);

ins(5, 5);
printar(que);

ins(234, 74);
printar(que);

ins(245, 2);
printar(que);

//ins(288, 100);
//printar(que);

printf("rem = %d\n", rem());
printar(que);

ins(288, 33);
printar(que);

printf("rem = %d\n", rem());
printar(que);
//Задание №2**************************************************
unsigned int h = 29393;
//printf("A number in decimal %d will be equal to %lld in binary\n", h, perevod(h));

 return 0;
}
