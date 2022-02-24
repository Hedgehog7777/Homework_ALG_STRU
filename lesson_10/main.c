#include <stdio.h>
#include <stdlib.h>
//Задание №1**************************************************
#define I char
#define SIZE 20

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

int prov(char* a)
{
 int i = 0;
 while(a[i]>0)
 {
  if (curs == -1)
  {
   if (a[i] == 40||a[i] == 91||a[i] == 123)
   {
    push(a[i]);
   }
   if (a[i] ==41||a[i] ==93||a[i] ==125)
   {
    printf("Error wrong bracket sequence!!!");
    return -1;
    break;
   }
  }
  else
  {
   if (a[i] == 40||a[i] == 91||a[i] == 123)
   {
    push(a[i]);
   }
   if (a[i] ==41||a[i] ==93||a[i] ==125)
   {
    if ((st[curs] ==40&&a[i] ==41)||(st[curs] ==91&&a[i] ==93)||(st[curs] ==123&&a[i] ==125))
    {
     pop();
    }
    else
    {
     printf("Error wrong bracket sequence!!!\n");
     return -1;
     break;
    }
   }
  }
  i++;
 }
 if(curs == -1)
 {
  printf("Correct bracket sequence\n");
  return 0;
 }
 else
 {
  printf("Error wrong bracket sequence!!!\n");
  return -1;
 }
}
//Задание №2**************************************************
typedef struct Node
{
 int dat;
 struct Node * next;
} Node;
 
typedef struct 
{
 Node * head;
 int size;
} Li;


void init(Li * lst)
{
lst->head = NULL;
lst ->size = 0;
}

void ins(Li * lst, int d)
{
 Node * new =(Node*) malloc(sizeof(Node));
 new->dat = d;
 new->next = NULL;
 Node * cur = lst->head;
 if (cur == NULL)
 {
  lst->head = new;
  lst->size++;
  return;
 }
 else
 {
  while(cur->next != NULL)
  {
   cur = cur->next;
  }
  cur->next = new;
  lst->size++;
 }
}

Node* rm(Li * lst, int data)
{
 Node * cur = lst->head;
 Node * parent = NULL;
 if(cur ==NULL)
 {
  return NULL;
 }
 while (cur->next != NULL && cur->dat != data)
 {
  parent = cur;
  cur = cur->next;
 }
 if (cur->dat != data)
 {
  return NULL;
 }
 if (cur == lst->head)
 {
 lst->head = cur->next;
 lst->size--;
 return cur;
 }
 parent->next = cur->next;
 lst->size--;
 return cur;
}

 void printNode(Node * n)
 {
  if (n == NULL)
  {
   printf("[]");
   return;
  }
  printf("[%d] ", n ->dat);
 }

void printList(Li * lst)
{
 Node * cur = lst->head;
 if ( cur == NULL)
 {
  printNode(cur);
 }
 else
 {
  do
  {
   printNode(cur);
   cur = cur->next;
  } while(cur != NULL);
 }
 printf(" Size: %d \n", lst->size);
}

void copy(Li * a, Li * b)
{
 int size = a->size;
 Node * cur = a->head;
 while (size !=0)
 {
  for(int i =0; i<size-1; i++)
  {
   cur= cur->next;
  }
  ins(b, cur->dat);
  size--;
  cur = a->head;
 }
}

//Задание №3**************************************************

int sort(Li * a)
{
 Node * cur = a->head;
 while (cur->next != NULL)
 {
  if(cur->dat > cur->next->dat)
  {
   return -1;
  }
  cur = cur->next;
 }
 return 0;
}
 



int main ()
{
//Задание №1**************************************************
 char str[] = {"(()*{ 24[2 5][ ]'}wtw!)"};
 prov (str);

//Задание №2**************************************************
Li * lst = (Li*)malloc(sizeof(Li));
init(lst);
Li * cp = (Li*)malloc(sizeof(Li));
init(cp);
ins(lst, 76);
ins(lst, 245);
ins(lst, 2);
ins(lst, 863);
ins(lst, 90);
printList(lst);
printList(cp);
copy(lst , cp);
printList(lst);
printList(cp);

//Задание №3**************************************************

Li * prim = (Li*)malloc(sizeof(Li));
init(prim);

ins(prim, 76);
ins(prim, 77);
ins(prim, 78);
ins(prim, 79);
printList(prim);

if(sort(prim) == 0)
{
 printf("List sorted\n");
}
else
{
 printf("List is not sorted\n");
}

if(sort(lst) == 0)
{
 printf("List sorted\n");
}
else
{
 printf("List is not sorted\n");
}


 return 0;
}
