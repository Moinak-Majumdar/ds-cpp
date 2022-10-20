#include<iostream>
#include<stdlib.h>

using namespace std;

struct Sll{
       int Data;
       struct Sll * Link; 
};

void display(struct Sll*ptr)
{
	struct Sll * temp;
     cout<<endl;
     if (ptr == NULL)
            cout<<"\n\tNo item to display, stack is empty ";
     else
     {
             cout<<"\tThe elements of the stack are ";
             temp = ptr;
             cout<<"\t";
             while(temp!=NULL)
             {
                        cout<<" "<< temp->Data<<", ";
                        temp=temp->Link;
             }
             cout<<endl;
     }
}
struct Sll* insert_at_end(struct Sll *ptr)
{
	struct Sll * temp, * temp1;
     int item;

     temp = (struct Sll *) malloc(sizeof(struct Sll));
     if (temp==NULL)
           cout<<endl<<"Memory is not available to create a new node";
     else
     {
           cout<<"\n\t Enter item (PUSH) : ";
           cin>>item;

           temp->Data=item;
           temp->Link=NULL;

           if (ptr==NULL) 	 //Address updation
              ptr=temp;
           else
           {
                temp1=ptr;
  				while(temp1->Link !=NULL)
				{
                     temp1=temp1->Link;
                }
				temp1->Link = temp;
           }
     }
     return (ptr);
}

struct Sll* delete_from_end(struct Sll *ptr)
{
	struct Sll *temp1,*temp2;

	temp1=ptr;
	if(temp1==NULL)
	{
		cout<<"\t\nstack is empty, no node to POP.";
	}
	else
	{
		while(temp1->Link!=NULL)
		{
			temp2=temp1;
			temp1=temp1->Link;
		}
		if(temp1==ptr)
			ptr=NULL;
		else
		{
			temp2->Link=NULL;
		}
			cout<<"\n\t Poped item is=>"<<temp1->Data;
			free(temp1);
	}
	return(ptr);
}

int main()
{
    int ch;
    struct Sll * Head=NULL;

    while(1)
    {		
		cout<<"\n********MENU********";
		cout<<endl<< "1. PUSH .";
		cout<<endl<< "2. POP.";
		cout<<endl<< "3. Display stck.\n4. Exit from progam.";
        cout<<endl<< "\nEnter the choice (1-4) : ";
        cin >> ch;
		
		switch(ch)
            {
                      case 1:  Head=insert_at_end(Head);
                               break;
                      case 2:  Head=delete_from_end(Head);
                               break;
    				  case 3: display(Head);
                               break;
					  case 4: exit(0);
					  		   break;
					  default: cout<<"\n\tWRONG CHOICE !!";
			}
	}
}
