#include<conio.h>
#include<iostream>

using namespace std;

int main()
{
	int arr[9],i,j,e,flag=1;
	
	// taking user input
	
	for (i=0;i<=9;i++)
	{
		cout<<"Enter element at position "<<i<<" ==> ";
		cin>>arr[i];
	}
	
	//scarching
	
	cout<<"\n\nEnter element to scarch ==> ";
	cin>>e;
	
	for(j=0;j<=9;j++)
	{
		if(arr[j]==e)
		{
				cout<<"\nElement "<<e<<" is present at position "<<j;
				flag=5;
				break;			
		}
		
	}
	if(flag==1)
		cout<<"\n\nElement "<<e<<" is not present in the array.";
	
	getch();
	return 0;
}
