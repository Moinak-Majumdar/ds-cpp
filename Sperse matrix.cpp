#include <iostream>
#include<stdlib.h>
using namespace std;

#define MAX 100

int data_s[MAX][3];

int len;

void insert(int r,int c,int val)
{
    data_s[len][0]=r;
    data_s[len][1]=c;
    data_s[len][2]=val;
    len++;
}

void print()
{
    cout << "\nDimension of Sparse Matrix: "
         << len << " x " << 3;
    cout << "\nSparse Matrix: 3 tuple form :\n\n";
	cout<<"       Row    Column   Value\n";
    for (int i = 0; i < len; i++) {

        cout <<"\t"<<data_s[i][0] << " "
             <<"\t"<<data_s[i][1] << " "
             <<"\t"<<data_s[i][2] << "\n";
    }
}

// Driver code
int main()
{
    int i, j;
    int r=5, c=4;
	 // Get the matrix
    int matrix[r][c];
    cout<<" Enter data for the matrix :\n";
    for(i=0;i<r;i++)
	{
		cout << endl;
		for(j=0;j<c;j++)
		{
            cout<<"\t["<<i<<"] ["<<j<<"] = ";
            cin>>matrix[i][j];
        }

    }

    // print the matrix
    cout << "\nMatrix:\n";
    for (i=0;i<r;i++)
	{
        for (j=0;j<c;j++)
		{
            cout<<"\t"<<matrix[i][j] << " ";
        }
        cout << endl;
    }
	//store value in sparse matrix
    for (i=0;i<r;i++)
        for (j=0;j<c;j++)
            if (matrix[i][j] > 0)
                insert(i, j, matrix[i][j]);

    // Print the Sparse Matrix
    print();

	//create new matrix and print.
	cout<<"\nNew matrix form the 3 tuple representation...\n\n";
	 int nm[r][c]; //new matrix.
	 int x=0,y=0,v=0;
	 for (i=0;i<r;i++)
    {
    	//initilize new matrix with default value 0.
    	for (j=0;j<c;j++)
    	{
    		nm[i][j]=0;
		}
	}

	for(i=0;i<len;i++)
	{
		x=data_s[i][0];
		y=data_s[i][1];
		v=data_s[i][2];
		nm[x][y]=v;
	}

	//print new matrix.
    for(i=0;i<r;i++)
    {
    	for(j=0;j<c;j++)
    	{
    		cout<<"\t"<<nm[i][j]<<" ";
		}
		cout<<endl;
	}

    return 0;
}
