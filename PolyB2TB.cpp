#include<iostream>
#include<conio.h>

using namespace std;

class poly
{
      private: int A[100], i;
               int deg;
               
      public:  void getpoly()
               {
                    cout << endl << "Enter the degree : ";
                    cin >> deg;
                    
                    if (deg > 99)  
                       cout << endl << "Degree of polynomial exceeds array ";
                    else
                    {
                        for(i = 0; i <= deg; i++)
                        {
                              cout << endl << "Enter coeff of x^"<<i<< ": ";
                              cin >> A[i];
                        }          
                        if (A[deg] == 0)
                        {
                           cout << endl << "Coeff of x^"<< deg << "is zero";
                           getch();
                           exit(0);
                        }
                    }
               }     
               void showpoly()
               {
                    int i;
                    //cout << endl << "The given polynomial is "; 
                    for(i = 0; i < deg; i++)
                    {
                          if(A[i] != 0)
                               cout << A[i] << ".x ^ " << i << " + ";
                    }
                    cout << A[deg] << ".x ^ " << deg;
               }
               poly Add(poly obj)
               {
                        poly R; 
                        
                        if (deg > obj.deg) 
                        {
                             for(i = 0; i <= obj.deg; i++)                 
                                   R.A[i] = A[i] + obj.A[i]; 
                             for(i = obj.deg+1; i<=deg; i++)
                                   R.A[i] = A[i]; 
                             R.deg = deg; 
                        }
                        else if (deg < obj.deg) 
                        {
                             for(i = 0; i <= deg; i++)                 
                                   R.A[i] = A[i] + obj.A[i]; 
                             for(i = deg+1; i<=obj.deg; i++)
                                   R.A[i] = A[i]; 
                             R.deg = obj.deg; 
                        }
                        else
                        {
                             for(i = 0; i <= deg; i++)                 
                                   R.A[i] = A[i] + obj.A[i]; 
                             R.deg = deg;                             
                        }
                        return (R); 
               }
                             
};

int main()
{
    poly p1;
    
    p1.getpoly();
    cout << endl << "The first polynomial is " ;
    p1.showpoly();
    
    poly p2; 
    
    p2.getpoly(); 
    cout << endl << "The second polynomial is " ;
    p2.showpoly(); 
    
    poly p3; 
    
    p3 = p1.Add(p2); 
    cout << endl << "The result of addition "; 
    p3.showpoly(); 
    
    getch();
    return 0;
}                    
                        
                        
                        
                        
