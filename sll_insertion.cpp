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

struct Sll* insert_in_beginning(struct Sll *ptr)
{
	struct Sll* temp1;
	int item;

	temp1=(struct Sll*)malloc(sizeof(struct Sll));
	if(temp1== NULL)
		cout<<"\n\t Memory is not available to create a new node !!";
	else
	{
		cout<<"\n\t Enter value for new node that will be inserted at the beginning of the list ==>";
		cin>>item;
		temp1->Data=item;
		temp1->Link=ptr;
		ptr=temp1;
	}
	return(ptr);
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
           cout<<"\n\t Enter the item to insert that will be inserted at the end of the list==>";
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

struct Sll* insert_at_spec_pos(struct Sll *ptr)
{
	int POS, count, item, i;
    struct Sll * temp, *temp1 ;

    cout<<"\n\tEnter the position to insert at an item: ";
    cin >> POS;


    temp=ptr;
    count= 0;
    while(temp!=NULL)
    {
               count=count+1; 	//Count the no of nodes
               temp=temp->Link;
    }

    if (POS<1||POS>count+ 1)
       cout<<"\tInvalid position specified ";
    else
    {
        temp=(struct Sll *)malloc(sizeof(struct Sll));

		if (temp==NULL)
			cout<<"\tMemory is not available";
		else
		{
            cout<<"\n\tEnter the item to insert: " ;
            cin>>item;
			temp->Data=item;

			if(POS==1)
			{
				temp->Link=ptr;
				ptr=temp;
			}
			else
			{
				//Traversal till the (POS - 1)th node
				i=1;
				temp1=ptr;
				while(i<POS-1)
				{
					temp1=temp1->Link;
					i=i+1;
				}
				//Address update
				temp->Link=temp1->Link;
				temp1->Link=temp;

            }
		}
    }
    return(ptr);
}

struct Sll* insert_after_spec_val(struct Sll *ptr)
{
	struct Sll *temp1,*temp2;
	int val,item;

	temp1=ptr;
	if(temp1==NULL)
		cout<<"\n List is empty...";
	else
	{
		cout<<"\n\t Enter the specific value :";
		cin>>val;

		while(temp1!=NULL)
		{
			if(temp1->Data==val)
				break;
			else
			{
				temp1=temp1->Link;
			}
		}
	}
	if(temp1==NULL)
	{
		cout<<"\n\t Specific value is not present in the list...";
		display(ptr);
	}
	else
	{
		temp2=(struct Sll*)malloc(sizeof(struct Sll));
		cout<<"\n\t Enter the item to insert: ";
    	cin>>item;
		if (temp2==NULL)
			cout<<"\tMemory is not available";
		else
			{
				temp2->Link=temp1->Link;
				temp1->Link=temp2;
				temp2->Data=item;
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
            cout<<endl<< "1. Insert in the beginning.";
            cout<<endl<< "2. Insert at the end.";
            cout<<endl<< "3. Insert at specific position.";
            cout<<endl<< "4. Insertion after a specific value.";
            cout<<endl<< "5. Display.\n6. Exit.";
            cout<<endl<< "\nEnter the choice (1-5) : ";
            cin >> ch;
            
            switch(ch)
            {
                      case 1:  Head=insert_in_beginning(Head) ;
                               break;
                      case 2:  Head=insert_at_end(Head);
                               break;
                      case 3:  Head=insert_at_spec_pos(Head);
                               break;
                      case 4:  Head=insert_after_spec_val(Head);
                               break;
                      case 5: display(Head);
                               break;
					  case 6: exit(0);
					  		   break;
					  default: cout<<"\n\tWRONG CHOICE !!";
			}
	}
}
