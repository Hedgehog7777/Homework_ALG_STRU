#include <stdio.h>
#include <stdlib.h>
#define TRE 50
#define SIZ 10000


typedef struct Node {
 int data;
 struct Node * left;
 struct Node * right;
} treen;

treen * Tins(treen * t, int dat)
{
 treen * ntr;
 ntr = (treen *) malloc(sizeof(treen));
 ntr->data = dat;
 ntr->left = NULL;
 ntr->right = NULL;
 treen * cur = t;
 treen * par = t;
 if (t == NULL)
 {
  t = ntr;
 }
 else
 {
  while (cur->data != dat)
  {
   par = cur;
   if(cur->data > dat)
   {
    cur = cur->left;
    if(cur == NULL)
    {
     par->left = ntr;
     return t;
    }
   }
   else
   {
    cur = cur->right;
    if(cur == NULL)
    {
     par->right = ntr;
     return t;
    }
   }
  }
 }
}

void printtree(treen * root)
{
 if(root)
 {
  printf("%d", root->data);
  if(root->left || root->right)
  {
   printf("(");
   if(root->left)
   {
    printtree(root->left);
   }
   else
   {
    printf("NULL");
   }
   printf(" , ");
   if (root->right)
   {
    printtree(root->right);
   }
   else
   {
    printf("NULL");
   }
   printf(")");
  }
 }
}




// Задание №1***************************************************************

int podsh(treen * tre)
{
 if(tre)
 {
  int l = 0;
  int r = 0;
  if(tre->left != NULL )
  {
   l = podsh(tre->left);
  }
  if(tre->right != NULL)
  {
   r = podsh(tre->right);
  }
  if(tre->right)
  {
   return 1+l;
  }
  else
  {
   return 1+r;
  }
 }
 else 
 {
  return 0;
 }
}

int provbal(treen * tre)
{
 return abs(podsh(tre->left)) - podsh(tre->right) <=1 ;
}

void trein(int a, treen *b)
{
 for (int i = 0; i < a; i++)
 {
  Tins(b, rand() %1000);
 }
}


// Задание №2***************************************************************

treen * search(treen *a, int d)
{
 if(a==NULL || a->data == d)
 {
  return a;
 }
 if(d < a->data)
 {
  return search(a->left, d);
 }
 else
 {
 return search(a->right, d);
 }
}

int main ()
{
// Задание №1***************************************************************

 int balans = 0;

 for (int i = 0; i < TRE; i++)
 {
  //printf ("Tree %d \n", i);
  treen * a = NULL;
  treen * b = Tins(a , rand()%1000);
  trein(SIZ, b);
  balans = balans + provbal(b) ? 1 : 0;
  //printtree(b);
  //printf ("\n\n\n");
  
  
  // Задание №2***************************************************************
  //printtree(search(b, 123));
  //printf ("\n\n\n");
 }

printf("%3d%%\n", balans/100*TRE);

 return 0;
}
