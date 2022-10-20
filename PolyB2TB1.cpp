//f(x, y) = x^2 + 2xy + y^2 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct poly 
{
       int coeff; 
       int x_expo; 
       int y_expo; 
       struct poly * link; 
}; 

struct poly *  createpoly(int x) 
{
    struct poly * first, * temp; 
    int i; 
    
    for(i = 1; i<=x ; i++) 
    {
          if (i == 1) 
          {
                temp = (struct poly *)malloc(sizeof(struct poly)); 
                
                first = temp; 
                temp -> link = NULL;
          }
          else
          {
                temp -> link = (struct poly *)malloc(sizeof(struct poly)); 
                temp = temp -> link;
                 
                temp -> link = NULL;                
          }   
          printf("\nEnter the data for term no %d ", i); 
          printf("\n------------------------------"); 
          printf("\nEnter coefficient : "); 
          scanf("%d", &temp -> coeff); 
          printf("\nEnter exponent of x: "); 
          scanf("%d", &temp -> x_expo); 
          printf("\nEnter exponent of y: "); 
          scanf("%d", &temp -> y_expo);  
    }
    
    return(first); 
}
void display(struct poly * poly)
{
     struct poly * temp; 
     if (temp == NULL)
         printf("\nNo polynomial to display "); 
     else
     {
         printf("\nThe given polynomial is \n"); 
         temp = poly; 
         while (temp != NULL) 
         {
               if (temp -> x_expo == 0)
                   printf("%d.y^%d + ", temp -> coeff, temp->y_expo); 
               else if (temp -> y_expo == 0)
                   printf("%d.x^%d + ", temp -> coeff, temp->x_expo);  
               else
                   printf("%d.x^%d.y^%d + ", temp -> coeff, temp->x_expo, temp -> y_expo); 
               temp = temp -> link; 
         }
         printf("\b\b\b   ");
     }
}   

int main() 
{
    struct poly * HEAD  = NULL; 
    int n; 
    
    printf("Enter the no. of terms in the function: "); 
    scanf("%d", &n); 
    
    HEAD = createpoly(n);
    display(HEAD); 
    
    getch(); 
    return 0; 
}

    
    
    
    
    
    
    
    
    
    

