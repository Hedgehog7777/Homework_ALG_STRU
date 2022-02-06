#include <stdio.h>
#include <math.h>
#define X 5
#define Y 5

//Задание №1 ***************************************************************

void printar(int arr[][X], int y, int x)
{
 for(int i=0; i<y; i++)
 {
  for(int j=0; j<x; j++)
  {
   printf("% 5d", arr[i][j]);
  }
  printf("\n");
 }
}

void booblar(int arr[Y][X], int y, int x)
{
 for (int i=0; i<(Y*X-1); i++)
 {
  for (int j=0; j<y; j++)
  {
   for (int k=0;k<x; k++)
   {
    int a=0;
    if(arr[j][k]>arr[j][k+1])
    {
     a = arr[j][k];
     arr[j][k] = arr[j][k+1];
     arr[j][k+1] = a;
    }
   }
  }
 }
} 

//Задание №3 ***************************************************************

void printar1(double *arr, int n)
{
 for(int i=0; i<n; i++)
 {
  printf("ar1[%d] = %5.2f\n", i, arr[i]);
 }
 printf("\n");
}

//функция для заполнения пользователем массива
double zap(double *arr, int n)
{
 for (int i=0; i<n; i++)
 {
  printf("Pleas enter a number: ar1[%d] = ", i);
  scanf("%lf", &arr[i]);
 }
}

//функция инвертирующая последовательность элементов массива
void invert(double *arr, int n)
{
 n = n-1;
 int i = 0;
 while(i<n-i)
 {
  int a = arr[i];
  arr[i] = arr[n-i];
  arr[n-i] = a;
  i++;
 }
}

//функция делающая расчет и вывод колличества элементов расчетное значение которых превышает 400
void popunogunagi(double *arr, int n)
{
 int att = 0;
 for (int i=0; i<n; i++)
 {
  double a = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);
  if(a>400)
  {
   att = att+1;
   printf("ar1[%d] = %5.2f > 400 \n", i, a);
  }
 }
 if (att>0)
 printf("Calculation result exceeds 400 in %d sequence count out of %d times\n", att, n);
 else printf("calculation result does not exceed 400");
} 

int main()
{
//Задание №1 ***************************************************************
 int arr[Y][X] ={
 {999, 24, 120, 22, 2},
 {1, 19, 18, 17, 247},
 {15, 147, 13, 12, 14},
 {5,  9,  8,  930,  6},
 { 5,  4,  550,  2,  0}};
 
 printar(arr, Y, X);
 printf("\n");
 
 booblar(arr, Y, X);
 printar(arr, Y, X);
 printf("\n");
 
//Задание №3 ***************************************************************
 int n = 11;
 double ar1[n];
 
 zap(ar1, n);
  
 invert(ar1, n);
 printf("\n");
 
 printar1(ar1, n);
 
 popunogunagi(ar1, n);
 
  return 0;
}
