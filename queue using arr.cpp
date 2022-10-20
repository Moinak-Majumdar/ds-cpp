#include<iostream>
#include<stdlib.h>

using namespace std;

#define size 10 

struct queue
{
	int front,rear;
	int number;
	int arr[size];
};

void initilize(struct queue *q)
{
	q->front=0;
	q->rear=-1;
	q->number=0;
}
int check(struct queue *q)
{
	if(q->number==0)
		return 1;  //empty
	else if(q->number==size)
		return 2;  //full
	else 
		return 3;
}
bool push(struct queue *q,int i)
{
	system("Color 7C");
	if(check(q)==2)
		return false;
	if(q->rear==size-1)
		q->rear=-1;
	q->arr[++q->rear]=i;
	q->number++;
	return true;
}
int pop(struct queue *q)
{
	int i;
	if(check(q)==1)
		return -9999;
	i=q->arr[q->front++];
	if(q->front==size)
		q->front=0;
	q->number--;
	return i;
}
void display(struct queue *q)
{
	int i;
	if(check(q)==1)
	{
		cout<<"\n\tQueue is empty !";
		return;
	}
	cout<<"\n\tThe elements of the queue are : ";
	for(i=q->front;i<=q->rear;i++)
	{
		cout<<q->arr[i]<<", ";
	}
	cout<<"\n";
}

main()
{
	int ch,ele,j;
	struct queue *obj=(struct queue *)malloc(sizeof(struct queue));
	initilize(obj);
	
	
	while(1)
	{
		
		cout<<"\n*****QUEUE_MENU*****";
		cout<<"\n 1. PUSH into queue.";
		cout<<"\n 2. POP from Queue.";
		cout<<"\n 3. Display.";
		cout<<"\n 4. Exit from progam.";
		cout<<"\n\n Choice(1-4)--> ";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :
				{
					cout<<"\n\tEnter the elelemt to Push :";
					cin>>ele;
					push(obj,ele);
					break;
				}
			case 2:
				{
					if(check(obj)==1)
						cout<<"\n\tQueue is empty, No item to POP.\n";
					else
					{
						j=pop(obj);
						cout<<"\n\t"<<j<<" is poped from the queue.\n";
					}
					break;
				}
			case 3:
				{
					display(obj);
					break;
				}
			case 4:
				exit(0);
			default:
				cout<<"\n\tWrong Choice :";
				break;		
		}
	
	}
}
