#include <stdio.h>
// Функция для вывода массива***************************************************************
void printar(int *arr, int x)
{
 for (int i=0; i<x; i++)
 {
  printf("%5d ", arr[i]);
 }
 printf("\n");
}
// Функция сортировки вставками***************************************************************
void VS(int *arr, int x)
{
 int t, p;
 for (int i=1; i<x; i++)
 {
  t = arr[i];
  p = i-1;
  while (p>=0&&arr[p]>t)
  {
   arr[p+1] = arr[p];
   p--;
  }
  arr[p+1] =t;
 }
}

// Функция быстрой сортьровки***************************************************************

void QS(int *arr, int y, int x)
{ 
  int a = y;
  int b = x;
  int c = a+((b-a)/2);
  int ar[3] = {arr[a], arr[b], arr[c]};
  VS(ar, 3);
  if(ar[1] == arr[a])
  {
   int f =arr[a];
   arr[a]=arr[c];
   arr[c]=f;
  }
  else
  { 
   if(ar[1] == arr[b])
   {
    int f =arr[b];
   arr[b]=arr[c];
   arr[c]=f;
   }
  }
  c = arr[c];
  
  do {
   while(arr[a] < c) a++;
   while(arr[b] > c) b--;
  
   if(a<=b)
   {
    int z = arr[a];
    arr[a] = arr[b];
    arr[b] = z;
    a++;
    b--;
   }    
  } while (a<=b);
 
  if (a<x) QS(arr, a, x);
  if (b>y) QS(arr, y, b);
 }
 
// Домашнее задание №1***************************************************************

void AQS(int *arr, int y, int x)
{
 if(x<=y) return;
 if (((x+1)-y) < 10)
 {
  VS(arr, ((x+1)-y));
  return;
 }
 else QS(arr, y, x);
}
// Домашнее задание №2***************************************************************
void bloksort(int *arr, int x)
{
 int max = x;
 int kor[11][x+1];
 
 for (int i=0;i<11;i++)
 {
  kor[i][max] = 0;
 }
 
 for (int k=1; k<10000; k*=10)
 {
 int b=0;
  for (int i=0; i<x;i++)
  {
   if ((arr[i]%2)==0)
   {
    int y = (arr[i]/k)%10;
    kor[y][kor[y][max]++]=arr[i];
    kor[10][b++]=i;
   }
  }
  int c=0;
  for (int i=0; i<10; i++)
  {
   for (int j=0; j<kor[i][max]; j++)
   {
    arr[kor[10][c]] = kor[i][j];
    c = c+1;
   }
   kor[i][max]=0;
  }
 }
}

int main()
{
 const int a = 25;
 int arr[a];
 arr[0] = 12;
 arr[1] = 22;
 arr[2] = 1;
 arr[3] = 33;
 arr[4] = 2;
 arr[5] = 7;
 arr[6] = 125;
 arr[7] = 25;
 arr[8] = 433;
 arr[9] = 5;
 arr[10] = 7;
 arr[11] = 76;
 arr[12] = 1;
 arr[13] = 4;
 arr[14] = 0;
 arr[15] = 63;
 arr[16] = 124;
 arr[17] = 21;
 arr[18] = 1;
 arr[19] = 340;
 arr[20] = 5;
 arr[21] = 78;
 arr[22] = 1;
 arr[23] = 9;
 arr[24] = 12;
  
 printar(arr, a);

 //bloksort(arr, a);

 AQS(arr, 0, a-1);
 
 printar(arr, a);
  
 return 0;
}
