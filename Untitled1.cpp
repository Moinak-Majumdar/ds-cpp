#include<iostream>
using namespace std;

int main()
{
	int org_arr[100][100];
	int sparse[100][3];
	int con_arr[100][100];
	int row=0,column=0,i=0,j=0,k=1,c=0,p=0,r1=0,c1=0;
	cout<<"Enter the no. of rows\n";
	cin>>row;
	cout<<"Enter the no. of columns\n";
	cin>>column;
	cout<<"Enter the elements\n";
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=column;j++)
		{
			cin>>org_arr[i][j];
			if(org_arr[i][j]==0)
				c++;
		}
	}
	cout<<"The matrix is:\n";
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=column;j++)
			cout<<org_arr[i][j]<<" ";
		cout<<endl;
	}
	p=(2*row*column)/3;
	if(c>=p)
	{
		//3 tuple form
		sparse[1][1]=row;
		sparse[1][2]=column;
		sparse[1][3]=row*column;
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				if(org_arr[i][j]!=0)
				{
					k=k+1;
					sparse[k][1]=i;
					sparse[k][2]=j;
					sparse[k][3]=org_arr[i][j];
				}
			}
		}	
		cout<<"The 3 tuple form is:\n";
		cout<<"Row\tCol\tValue\n";
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=3;j++)
				cout<<sparse[i][j]<<"\t";
			cout<<endl;
		}	
		//Conversion from sparse to original
		r1=2;
		c1=1;
		for(i=1;i<=sparse[1][1];i++)
		{
			for(j=1;j<=sparse[1][2];j++)
			{
				if(r1<=k)
				{
					if((i == sparse[r1][c1]) && (j == sparse[r1][c1+1]))
					{
						con_arr[i][j]=sparse[r1][c1+2];
						r1=r1+1;
					}
				}
				else
					con_arr[i][j]=0;
			}
		}
		cout<<"Now the original matrix is:\n";
		for(i=1;i<=sparse[1][1];i++)
		{
			for(j=1;j<=sparse[1][2];j++)
				cout<<con_arr[i][j]<<" ";
			cout<<endl;
		}
	}
	else
		cout<<"The given matrix is not a sparse matrix\n";
	return 0;
}
