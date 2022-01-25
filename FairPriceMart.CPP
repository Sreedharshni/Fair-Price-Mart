#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void deQueue();

int c;
struct Queue
 {
      int lineno;
      char custname[20];
      float price;
      struct Queue *next;

 }*front,*back,*first,*last;
void enQueue()
 {
       struct Queue *temp;
       temp=(struct Queue*)malloc(sizeof(struct Queue));
       c++;
       temp->lineno=c;
       clrscr();
       gotoxy(25,10);
       printf("Line Queue Number: 00%d",c);
       gotoxy(25,12);
       printf("Enter Family Head Name:");
       gotoxy(50,12);
       scanf("%s",temp->custname);
       temp->next=0;
       if(front==0)
	  {
	  front=temp;
	  back=temp;
	  }
       else
	  {
	  back->next=temp;
	  back=temp;
	  }
 }
 void dispQueue()
  {
    struct Queue *temp;
    clrscr();
    if(c==0)
	{
	gotoxy(25,12);
	printf("Empty Queue...");
	getch();
	return;
	}
    temp=front;
    printf("Queue Line Number      Name     \n");
    printf("---------------------------------------------\n");
    while(temp!=0)
      {
      printf("     00%d                %s\n",temp->lineno,temp->custname);
      temp=temp->next;
      }
    printf("---------------------------------------------\n");
    getch();
  }
 void dellist()
  {
    struct Queue *temp;
    clrscr();
    if(first==0)
	{
	gotoxy(25,12);
	printf("No Delivered List...");
	getch();
	return;
	}
    temp=first;
    printf("Queue Line Number      Name          Price \n");
    printf("---------------------------------------------\n");
    if(first==last)
      {
      printf("     00%d                %s      %f\n",temp->lineno,temp->custname,temp->price);
      printf("---------------------------------------------\n");
      getch();
      return;
      }
    while(1)
      {
      printf("     00%d                %s      %f\n",temp->lineno,temp->custname,temp->price);
      if(temp==last)
	   break;
      temp=temp->next;
      }
    printf("---------------------------------------------\n");
    getch();
  }

int menu();
int main()
{
 int opt;
 first=0;
 last=0;
 front=0;
 back=0;
 do
 {
  opt=menu();
  switch(opt)
  {
   case 1 : enQueue();
	    break;
   case 2 : deQueue();
	    break;
   case 3 : dispQueue();
	    break;
   case 4 : dellist();
	    //printf("Delivered list : ");
	    //getch();
	    break;
   case 5 : exit(0);
	    getch();
	    break;
    }
  }while(1);
 }
void deQueue()
 {
    struct Queue *temp;
    char ch;
    clrscr();
    if(front==0)
       {
       printf("Queue is Empty....");
       getch();
       return;
       }
    clrscr();
    gotoxy(15,10);
    printf("Line Queue Number: 00%d",front->lineno);
    gotoxy(15,12);
    printf("Family Head Name:%s",front->custname);
    gotoxy(15,14);
    printf("Choose Things you want:press y for yes,n for no..\n");
    gotoxy(15,16);
    printf("Wheat 5Ks         [   ]");
    gotoxy(15,17);
    printf("Rice  25Kg        [   ]");
    gotoxy(15,18);
    printf("Kerosine 5 Liters [   ]");
    gotoxy(36,16);
    fflush(stdin);
    ch=getche();
    front->price=0;
    if(ch=='y')
	  {
	  front->price+=40;
	  gotoxy(40,16);
	  printf("40Rs.");
	  }
    gotoxy(36,17);
    fflush(stdin);
    ch=getche();
    if(ch=='y')
	  {
	  front->price+=50;
	  gotoxy(40,17);
	  printf("50Rs.");
	  }
    gotoxy(36,18);
    fflush(stdin);
    ch=getche();
    if(ch=='y')
	  {
	  front->price+=80;
	  gotoxy(40,18);
	  printf("80Rs.");
	  }
    gotoxy(15,19);
    printf("Total Bill: %f",front->price);
    if(first==0)
	  {
	  first=last=front;
	  }
    if(front==back)
	  {
   //	  free(front);
	  if(first==0)
		first=last=front;

	  else
	       last=front;
	  front=back=0;
	  }
    else
	  {
	  if(first==0)
		first=last=front;
	  else
	       last=front;
	  front=front->next;
	  }
    getch();
 }
int menu()
 {
  int opt;
  clrscr();
  gotoxy(30,11);
  printf("Ration shop ");
  gotoxy(30,13);
  printf("1. Issue token : ");
  gotoxy(30,14);
  printf("2. Issue items :");
  gotoxy(30,15);
  printf("3. Queue lists : ");
  gotoxy(30,16);
  printf("4. Delivered list ");
  gotoxy(30,17);
  printf("5. Exit ");
  gotoxy(30,18);
  printf("Enter option :");
  gotoxy(45,18);
  scanf("%d",&opt);
  return(opt);
 }
