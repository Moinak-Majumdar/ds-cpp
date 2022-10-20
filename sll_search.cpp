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

struct Sll* search_sll(struct Sll *ptr)
{
	struct Sll *temp1;
	int i=1,val;

	if(ptr==NULL)
		cout<<"\n\tList is empty, no node to search.";
	else
	{
		cout<<"\n\tEnter value to scarch==>";
		cin>>val;
		temp1=ptr;

		while(temp1!=NULL)
		{
			if(temp1->Data==val)
			{
				cout<<"\n\t Value found...";
				cout<<"\n\t node no is==>"<<i;
				break;
			}
			else
			{
				temp1=temp1->Link;
				i++;
			}

		}
	if(temp1==NULL)
			{
				cout<<"\n\tvalue :"<<val<<" is not ptresent in the list..";
				display(ptr);
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
        	cout<<endl<< "2. search a given element.";
            cout<<endl<< "3. Display.\n4. Exit.";
            cout<<endl<< "\nEnter the choice (1-4) : ";
            cin >> ch;

            switch(ch)
            {
                     
                      case 1:  Head=insert_at_end(Head);
                               break;
                      case 2:  Head=search_sll(Head);
					  		   break;
					  case 3: display(Head);
                               break;
					  case 4: exit(0);
				    		   break;
					  default: cout<<"\n\tWRONG CHOICE !!";
					

            }
    }
}
