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

struct Sll* delete_from_beginning(struct Sll *ptr)
{
	struct Sll *temp;
	if(ptr==NULL)
		cout<<"\t\nList is empty, no node to delete.";
	else
	{
		temp=ptr;
		ptr=ptr->Link; //2nd node will be new head.
		cout<<"\t\n Deleted item is=>"<<temp->Data;
		free(temp);
	}

	return(ptr);
}

struct Sll* delete_from_end(struct Sll *ptr)
{
	struct Sll *temp1,*temp2;

	temp1=ptr;
	if(temp1==NULL)
	{
		cout<<"\t\nList is empty, no node to delete.";
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
			cout<<"\t\n Deleted item is=>"<<temp1->Data;
			free(temp1);
	}
	return(ptr);
}
struct Sll* delete_from_pos(struct Sll *ptr)
{
	struct Sll *temp1, *temp2;
    int i,count,POS;

       if(ptr==NULL)
		cout<<"\n\tList is empty, no node to delete.";
       else
       {
		    cout<<"\n\tEnter the position from where node to be deleted :";
		    cin >> POS;

     		count=0 ;
        	temp1=ptr;
		    while(temp1!=NULL)
		    {
		          count=count+1;
		          temp1=temp1->Link ;
            }
			if (POS<1 || POS>=count)	 //POS is Valid or Invalid
      			   cout<<"\tInvalid position specified, deletion is not possible";
    		else
    		{
                i=1;
			    temp1=ptr;
			    while(i<=POS-1)
			    {
				  temp2=temp1;
				  temp1=temp1->Link ;
			      i=i+1;
	            }
    			if (POS==1)
				   ptr =ptr->Link;
    			else
			       temp2->Link=temp1->Link ;

                cout<<"\n\tDeleted item is " << temp1 -> Data;
                free(temp1);
            }
	  }
	  return(ptr);
}

struct Sll* delete_the_spec_val(struct Sll *ptr)
{
	struct Sll *temp1,*temp2;
	int i=1,val;

	if(ptr==NULL)
		cout<<"\n\tList is empty, no node to delete.";
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
				temp2=temp1;
				i++;
			}

		}
		if(temp1==NULL)
		{
				cout<<"\n\tvalue : "<<val<<" is not ptresent in the list..";
				display(ptr);
		}
		else
		{
				cout<<"\n\t Deleted element is :"<<temp1->Data;
				temp2->Link=temp1->Link;
				free(temp1);
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
            cout<<endl<< "1. Insert Element.";
            cout<<endl<< "2. Delete from beginning.";
            cout<<endl<< "3. Delete from end.";
            cout<<endl<< "4. Delete from Specific position.";
            cout<<endl<< "5. Delete Specific element.";
            cout<<endl<< "6. Display.\n7. Exit.";
            cout<<endl<< "\nEnter the choice (1-7) : ";
            cin >> ch;

            switch(ch)
            {
                     
                      case 1:  Head=insert_at_end(Head);
                               break;
                      case 2:  Head=delete_from_beginning(Head);
                               break;
                      case 3:  Head=delete_from_end(Head);
                               break;
                      case 4:  Head=delete_from_pos(Head);
                               break;
					  case 5:  Head=delete_the_spec_val(Head);
					  		   break;
					  case 6:  display(Head);
                               break;
					  case 7: exit(0);
					  		   break;
					  default: cout<<"\n\tWRONG CHOICE !!";
			}
    }
}
