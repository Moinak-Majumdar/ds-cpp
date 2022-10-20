#include<iostream>
#include<stdlib.h>

using namespace std;

int stack[10],top=-1;

void Push(int n)
{
	if(top==99)
		{
			cout<<"\n\tStack overflow.";
			exit(0);
		}
		stack[++top]=n;
}
int Pop()
{
	int item;
	if(top==-1)
		{
			cout<<"\n\tStack Underflow.";
			exit(0);
		}
	return(stack[top--]);
}
void Display()
{
	int i;
	cout<<"\n\t The elements of the Stack are : ";
	for(i=0;i<=top;i++)
		cout<<stack[i]<<", ";
}
main()
{
	int ch,ele,j;
	while(1)
	{
		cout<<"\n*****STACK_MENU*****";
		cout<<"\n 1. PUSH into stack.";
		cout<<"\n 2. POP from stack.";
		cout<<"\n 3. Display.";
		cout<<"\n 4. Exit from progam.";
		cout<<"\n Enter choice (1-4)--> ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{
					cout<<"\n\tEnter element to PUSH : ";
					cin>>ele;
					Push(ele);
					break;
				}
			case 2:
				{
					j=Pop();
					cout<<"\n\tElement "<<j<<" Poped from stack.\n";
					break;
				}
			case 3:
				{
					Display();
					break;
				}
			case 4:
				exit(0);
			default :
				cout<<"\n\t Wrong choice ! ";			
		}
	}
}
