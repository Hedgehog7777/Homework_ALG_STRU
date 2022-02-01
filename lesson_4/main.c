#include <stdio.h>

#define SIZX 5
#define SIZY 5

//Задание №1***********************************************************************************
long perev(int a)
{
 if(a > 0)
 {
  return a%2 + perev(a/2)*10;
  if (a = 1)
  {
   return (a*10)%2 + perev(a/2)*10;
   a = 0;
  }
 }
 else
 {
  return 0;
 }
}
//Задание №2.1***********************************************************************************
int voz(int a, int b)
{
 if(b > 1)
 {
  return a*voz(a,b-1);
 }
 else
 {
  return a;
 }
}
//Задание №2.2***********************************************************************************
int voz1(int a, int b)
{
 if(b>1)
 {
  if(b%2 == 0)
  {
   return voz1(a*a, b/2);
  }
  else
  {
   return a*voz1(a, b-1);
  }
 }
 else
 {
  return a;
 }
}
//Задание №3***********************************************************************************
int kor(int arr[][SIZX], const int y, const int x)
{
 if (x==0&&y==0)
  return 0;
 else if (x!=0&&y==0)
 
	if (arr[0][x-1]==0&&arr[0][x]==0)
	 
	  if(x > 1&&kor(arr, y, x-1)==0)
	   return 0;
	  else return 1;
	  
	else return 0;
	
       else if (x==0&&y!=0)
      
		if (arr[y-1][0]==0&&arr[y][0]==0)
		 
		 if(y > 1&&kor(arr, y-1, x)==0)
		  return 0;
		 else return 1;
		 
		else return 0;
		
	     else if (arr[y][x]!=0)
	    
			return 0;
			
		   else return kor(arr, y-1, x) + kor(arr, y, x-1);
}
//*********************************************************************************************
int main()
{
 
 int a =8757;
 printf("Задание №1\n");
 printf("Число в десятичной системе счисления: %d \n", a);
 printf("Это же числов двоичной системе счисления:%li\n\n", perev(a));

 
 int b =7;
 int c =9;
 printf("Задание №2.1\n");
 printf("Число %d нужно возвести в степень %d \n", b, c);
 printf("Рекурсивно: %d \n\n", voz(b, c));

 printf("Задание №2.1\n");
 printf("Рекурсивно используя свойства четности степеней: %d\n\n", voz1(b, c));

 printf("Задание №3\n");
 printf("Реализовать нахождение количества маршрутов шахматного короля с препятствиями\n");
 printf("Массив с препятствиями выглядит так:\n");
 int arr[SIZY][SIZX] = {
 {0, 1, 0, 1, 0,},
 {0, 1, 0, 0, 0,},
 {0, 0, 0, 1, 0,},
 {1, 0, 0, 0, 0,},
 {0, 0, 0, 0, 0,},
 };
 
 for (int i=0; i < SIZX; i++)
 {
  for (int j=0; j < SIZY; j++)
  {
   printf("%5d", arr[i][j]);
  }
  printf("\n");
 }
 
 printf("\nМаршруты короля выглядят так:\n");
 
 for (int i=0; i < SIZX; i++)
 {
  for (int j=0; j < SIZY; j++)
  {
   printf("%5d", kor(arr, i, j));
  }
  printf("\n");
 }

return 0;
}
