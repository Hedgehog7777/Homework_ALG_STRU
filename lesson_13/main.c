#include <stdio.h>

//Задание №1**************************************************

#define GRAF 6

int matr[GRAF][GRAF]= {
{0, 1, 1, 0, 0, 0,},
{0, 0, 0, 1, 1, 1,},
{0, 0, 0, 0, 0, 1,},
{1, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 0, 0,},
{0, 0, 0, 0, 1, 0,}};

#define I unsigned int

int curs = -1;
I st[GRAF];

int push(I dat)
{
 if (curs < GRAF-1)
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
int visit [GRAF] = {0};
void obhod(int a)
{
 if(curs == -1)
 {
  visit[a] =1;
  push (a);
  printf("%d -", a);
  for (int i = 0; i < GRAF; i++)
  {
   if (matr[a][i]==1 && !visit[i])
   {
    obhod(i);
   }
  }
  pop();
  printf("\n");
  for (int i = 0; i<GRAF; i++)
  {
   visit [i] = 0;
  }
 }
 if(curs > -1)
 {
  visit[a] =1;
  push (a);
  printf(" %d", a);
   for (int i = 0; i < GRAF; i++)
  {
   if (matr[a][i]==1 && !visit[i])
   {
    obhod(i);
   }
  }
  pop();
 }
}

//Задание №2**************************************************

void rekobhod()
{
 if (visit[GRAF-1] == 1)
 {
  int a = 5;
  int n = 0;
  for(int i = 0; i<GRAF; i++)
  {
   if(a!=i)
   {
    if (matr[i][a]==1)
    {
     n++;
    }
   }
   if(i == GRAF-1)
   {
     printf("The number of pludegrees of entering vertex %d is %d\n", a, n);
   }
  } 
  for (int i = 0; i<GRAF; i++)
  {
   visit [i] = 0;
  }
 }
 else
 {
  int n = 0;
  int a = 0;
  for(int i = 0; i<GRAF; i++)
  {
   
   if(visit[i] == 0)
   {
    a = i;
    visit[i] = 1;
    break;
   }
  }
  for(int i = 0; i<GRAF; i++)
  {
   if(a!=i)
   {
    if (matr[i][a]==1)
    {
     n++;
    }
    if(i == GRAF-1)
    {
     printf("The number of pludegrees of entering vertex %d is %d\n", a, n);
    }
   }
  }
  rekobhod();
 }
}


 
void matobhod(int a[GRAF][GRAF])
{
 for(int i = 0; i<GRAF; i++)
 {
 int n = 0;
  for(int j =0; j<GRAF; j++)
  {
   if(i!=j)
   {
    if (matr[j][i]==1)
    {
     n++;
    }
   }
  } 
  a[0][i] = n;
  a[1][i] = i;
 }
 int b = 0;
 for(int j = 0; j<GRAF; j++)
 {
  for(int i = 0; i<GRAF-1; i++)
  {
   if(a[0][i]<a[0][i+1])
   {
    b = a[0][i];
    a[0][i] = a[0][i+1];
    a[0][i+1] = b;
    b = a[1][i];
    a[1][i] = a[1][i+1];
    a[1][i+1] = b;
   }
  }
 }
} 

void printo(int a[GRAF][GRAF])
{
 for (int i = 0; i<GRAF; i++)
 {
  printf("The number of pludegrees of entering vertex %d is %d\n", a[1][i], a[0][i]);
 }
}


void printm(int a[GRAF][GRAF])//для вывода массива 
{
 for(int j = 0; j <2; j++)
 {
  printf("m[%d] = {", j);
  for(int i = 0; i<GRAF; i++)
  {
   if(i!=GRAF-1)
   {
    printf("%3d,", a[j][i]);
   }
   else
   {
    printf("%3d", a[j][i]);
   }
  }
  printf("}\n");
 }
}

int main ()
{

 
 obhod(0);

 rekobhod();
 
 int m [GRAF][GRAF] = {0};
 matobhod(m);
 printm(m);
 printo(m);
 
 
 
 return 0;
}
