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
            cout<<"\n\tNo node to display, list is empty ";
     else
     {
             cout<<"\tThe elements of the list are ";
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
           cout<<"\n\t Enter item : ";
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

struct Sll* revrse_sll(struct Sll *ptr)
{
	struct Sll *prev,*curr,*next;

	curr=ptr;
	if(ptr==NULL)
		cout<<"\n\tlist is empty.";
	else
	{
		if(curr->Link==NULL)
		{
			cout<<"\n\tThere is only one node present in the list.";
			cout<<"\n\tReversal is not possiable";
				display(ptr);
		}
		else
		{
			while(next!=NULL)
			{
				next=curr->Link;
				curr->Link=prev;
				prev=curr;
				curr=next;
			}
			ptr=prev;
			cout<<"\n\t SLL reversed successfully.\n";
		}
	}
	return(ptr);
}

int main()
{
    int ch;
    struct Sll * Head=NULL;

    while(1)
    {		cout<<"\n********MENU********";
           
            cout<<endl<< "1. Insert element.";
        	cout<<endl<< "2. reverse the list.";
            cout<<endl<< "3. Display.\n4. Exit.";
            cout<<endl<< "\nEnter the choice (1-4) : ";
            cin >> ch;

            switch(ch)
            {
                     
                      case 1:  Head=insert_at_end(Head);
                               break;
                      case 2:  Head=revrse_sll(Head);
					  		   break;
					  case 3: display(Head);
                               break;
					  case 4: exit(0);
				    		   break;
					  default: cout<<"\n\tWRONG CHOICE !!";
					

            }
    }
}
