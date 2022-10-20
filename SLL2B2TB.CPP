#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std; 

struct SLL{
       int DATA; 
       struct SLL * LINK; 
}; 
struct SLL * insert_in_beginning(struct SLL * ptr)
{
       struct SLL * temp; 
       int item; 
       
       temp = (struct SLL *)malloc(sizeof(struct SLL)); 
       
       if (temp == NULL)
                cout << endl << "Memory is not available to create a new node "; 
       else
       {
                cout << endl << "Enter the value for the new node: "; 
                cin >> item; 
                
                temp -> DATA = item; 
                temp -> LINK = ptr; 
                ptr = temp;           
       }
       
       return(ptr);                    
}

struct SLL * insert_at_end(struct SLL * ptr) 
{
     struct SLL * temp, * temp1; 
     int item; 
     
     temp = (struct SLL *) malloc(sizeof(struct SLL)); 
     if (temp == NULL) 
           cout << endl << "Memory is not available to create a new node";
     else
     {
           cout << endl << "Enter the item to insert: " ; 
           cin >> item; 
           //Insertion of value 
           temp -> DATA = item; 
           temp -> LINK = NULL; 
           //Address updation 
           if (ptr == NULL) 
              ptr = temp; 
           else
           {
               temp1 = ptr; 
  			   while(temp1 -> LINK != NULL) 
			   {
                           temp1 = temp1 -> LINK; 
               }
			   temp1 -> LINK = temp; 	
           }
     }
     return (ptr); 
}

void display(struct SLL * ptr)
{
     struct SLL * temp; 
     cout<<endl<<endl;
     if (ptr == NULL)
             printf("\n\tNo node to display, list is empty "); 
     else
     {
             printf("\n\tThe elements of the list are "); 
             temp = ptr; 
             cout<<"\t";
             while(temp != NULL) 
             {
                        printf("%d ", temp -> DATA); 
                        temp = temp -> LINK; 
             }
     }                                   
}

struct SLL * insert_at_pos(struct SLL * ptr) 
{
    int POS, N, item, i; 
    struct SLL * temp, *temp1 ; 
    
    cout << endl << "Enter the position to insert at an item: "; 
    cin >> POS; 
    
    //Count the no of nodes in the list 
    temp = ptr; 
    N = 0; 
    while(temp != NULL) 
    {
               N = N + 1; 
               temp = temp -> LINK; 
    }    
    
    if (POS < 1 || POS > N + 1) 
       cout << endl << "Invalid position specified "; 
    else
    {
        temp = (struct SLL *)malloc(sizeof(struct SLL)); 

		if (temp == NULL) 
			cout << endl << "Memory is not available"; 
		else
		{
            cout << endl << "Enter the item to insert: " ; 
            cin >> item; 
			temp -> DATA = item;  

			if(POS == 1) 
			{
				temp -> LINK = ptr;  
				ptr = temp; 
			}
			else
			{
				//Traversal till the (POS - 1)th node 
				i = 1; 
				temp1 = ptr; 
				while ( i < POS - 1) 
				{
					temp1 = temp1 -> LINK; 
					i = i + 1; 
				}
				//Address update
				temp -> LINK = temp1 -> LINK;
				temp1 -> LINK = temp;  
			
            }
		}
    } 
    return(ptr); 
}

struct SLL* insert_after_val(struct SLL * ptr) 
{
     struct SLL * temp, * temp1; 
     int VAL, ITEM;
     
     if (ptr == NULL) 	// List is empty 
		cout << endl << "List is empty, insertion is not possible"; 
     else
     {	
        cout << endl << "Enter the value after which  a new will be created "; 
        cin >> VAL;         
        //To search for a node with 'VAL' 
		temp = ptr; 
		while (temp != NULL) 
		{ 
			if (temp -> DATA == VAL)
                break ; 
            else
				temp = temp -> LINK; 
		}

		if(temp == NULL) 
			cout << endl << "VAL is not found in the list, insertion is not possible"; 
        else
        {
            cout << endl << "Enter the item to insert: "; 
            cin >> ITEM; 
                        
			temp1 = (struct SLL *)malloc(sizeof(struct SLL)); // 'getnode()' is a procedure to create a node dynamically 

			if(temp1 == NULL)
				cout << endl << "Memory is not available "; 
			else
			{
				temp1 -> DATA = ITEM;  

				temp1 -> LINK = temp -> LINK; 
				temp -> LINK = temp1; 
			}
		} 
    }
    return(ptr); 
}

struct SLL * delete_from_beginning(struct SLL * ptr)
{
       struct SLL * temp; 
       
       if (ptr == NULL)
               cout << "List is empty, deletion is not possible "; 
       else 
       {
            temp = ptr; 
            cout << "Deleted item is " << temp -> DATA ; 
            ptr = ptr -> LINK; 
            free(temp); 
       }
       return(ptr); 
}


struct SLL * delete_from_end(struct SLL * ptr)
{
       struct SLL * temp1, * temp2; 
       
       if (ptr == NULL)
		  cout << endl << "List is empty, deletion is not possible "; 
       else
       {
	   		temp1 = ptr;
		    while(temp1 -> LINK != NULL) 
		    {
			            temp2 = temp1 ; 
            			temp1 = temp1 -> LINK ; 
            }
            if (temp1 == ptr)
			   ptr = NULL; 
            else
                temp2 -> LINK = NULL; 
            
            cout << endl << "Deleted item is " << temp1 -> DATA; 
		    free(temp1) ; 
      }
      return (ptr); 
}

struct SLL * delete_from_POS(struct SLL * ptr)
{
       struct SLL * temp1, * temp2; 
       int i, N, POS; 
       
       if (ptr == NULL)
		cout << endl << "List is empty, deletion is not possible "; 
       else
       {
		    cout << endl << "Enter the position from where node to be deleted :"; 
		    cin >> POS; 
            //POS is Valid or Invalid 
     		N = 0 ; 
        	temp1 = ptr; 
		    while (temp1 != NULL) 
		    {
		          N = N + 1; 
		          temp1 = temp1 -> LINK ; 
            }

    		if (POS < 1 || POS >= N)
      			   cout << "Invalid position specified, deletion is not possible"; 
    		else
    		{
                i = 1; 
			    temp1 = ptr; 
			    while (i <= POS - 1) 
			    { 
				  temp2 = temp1 ; 
				  temp1 = temp1 -> LINK ; 
			      i = i + 1; 
	            }
		
    			if (POS == 1) 
				   ptr = ptr -> LINK;  
    			else
			       temp2 -> LINK = temp1 -> LINK ; 
                   
                cout << endl << "Deleted item is " << temp1 -> DATA;    
                free(temp1); 		
            }
	  }
	  return (ptr); 
}

struct SLL * search_sll(struct SLL * ptr)
{
	struct SLL* temp1; 
	int val,i=0;
	
	if(ptr==NULL)
		cout<<"\n List is empty, no node to scarch";
	else
	{
		cout<<"\n Enter value to scarch==>";
		cin>>val;
		temp1=ptr;
		
		while(temp1 != NULL)
		{
			if(temp1->DATA == val)
			{
				cout<<"\n\t Value found...";
				cout<<"\n\t node no is==>"<<i;
				break;
			}
			else 
				temp1=temp1->LINK;
				i++;
		}
		if(temp1==NULL)
			cout<<"\n\t Value not found in the list !!";	
	}
}

int main()
{
    int ch; 
    struct SLL * HEAD = NULL; 
    
    while(1)
    {
            cout << endl << "1. Insert in the beginning"; 
            cout << endl << "2. Insert at the end"; 
            cout << endl << "3. Insert at specific position"; 
            cout << endl << "4. Insertion after a specific value";
            cout << endl << "5. Delete from beginning"; 
            cout << endl << "6. Delete from end";  
            cout << endl << "7. Delete from position";
            cout << endl << "8. search a given element";
            cout << endl <<	"9. reverse the list";
            cout << endl << "10. Display\n11. Exit"; 
            cout << endl << "\nEnter the choice: "; 
            cin >> ch; 
            
            switch(ch)
            { 
                      case 1:  HEAD = insert_in_beginning(HEAD) ; 
                               break; 
                      case 2:  HEAD = insert_at_end(HEAD); 
                               break; 
                      case 3:  HEAD = insert_at_pos(HEAD); 
                               break; 
                      case 4:  HEAD = insert_after_val(HEAD); 
                               break;                            
                      case 5:  HEAD = delete_from_beginning(HEAD); 
                               break; 
                      case 6:  HEAD = delete_from_end(HEAD); 
                               break; 
                      case 7:  HEAD = delete_from_POS(HEAD); 
                               break; 
					  case 8:  HEAD = search_sll(HEAD);
					  		   break;
					//  case 9: HEAD = rev_sll(HEAD);
					  		   break;                   
                      case 10:  display(HEAD); 
                               break; 
                      case 11:  exit(0); 
            }
    }
}

                      
                      
                      
                      
                      
                      
            
