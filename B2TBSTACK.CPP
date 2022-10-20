#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

using namespace std;

struct queu{
       int data;
       struct queu * link;
};
struct queu * FRONT = NULL, * REAR = NULL;
int count = 0;

void deleteq()
{
    struct queu * temp;

    if (FRONT == NULL)
        cout << endl << "Queue is empty, no item to delete\n";
    else
    {
        cout << endl << "Deleted item is " << FRONT -> data;

        temp = FRONT;
        if ( FRONT == REAR)
        {
            FRONT = NULL;
            REAR = NULL;
        }
        else
            FRONT = FRONT -> link;

        free(temp);
    }
}

void display()
{
     struct queu * temp;
     if (REAR == NULL)
        cout << endl << "Queue underflow, no item to display \n";
     else
     {
         cout << endl << "The elements of the Queue are ";
         temp = FRONT ;
         while (temp != NULL)
         {
             cout << temp -> data << "   ";
             temp = temp -> link;
         }
         cout << endl;
     }
}

void insertq()
{
     struct queu * temp;
     int item;

     if (count == SIZE)
         cout << endl << "Queue is full, item can not be inserted\n";
     else
     {
         temp = (struct queu *)malloc(sizeof(struct queu));

         if (temp == NULL)
             cout << endl << "Memory is not available, item can not be inserted\n";
         else
         {
             cout << endl << "Enter the item to push: ";
             cin >> item;

             temp -> data = item;
             temp -> link = NULL;

             if (REAR == NULL)     //Stack is empty
             {
                FRONT = temp;
                REAR = temp;
             }
             else
             {
                 REAR -> link = temp;
                 REAR = temp;
             }

             count = count + 1;
         }
     }
}



int main()
{
    int ch;

    while(1)
    {
             cout << endl << "1. Insert\n2. Delete\n3. Display\n4. Exit";
             cout << endl << "Enter your choice: ";
             cin >> ch;

             switch(ch)
             {
                       case 1: insertq();
                               break;
                       case 2: deleteq();
                               break;
                       case 3: display();
                               break;
                       case 4: exit(0);
             }
    }

    return 0;
}
