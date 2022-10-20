#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid -1,x);
		
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

int main(void)
{
	int n,k=0,l=0;
	cout<<"Binary Scarch on array :"<<"\n\tEnter number of elements for array : ";
	cin>>n;
    int arr[n];
	while(k<n)
	{
		cout<<"\n\t\tEnter element arr["<<k<<"] : ";
		cin>>arr[k];	
		k++;
	}
	cout<<"\n\n Array elements are : ";
	while(l<n)
	{
		cout<<arr[l]<<"\t";
		l++;
	}
	int ch,result,m,x;
	while(1)
	{
		cout<<"\n\n ********MENU********"<<"\n PRESS 1 : To scarch from array.";
		cout<<"\n PRESS 2 : To exit program.";
		cout<<"\n CHOICE -->  ";
		cin>>ch;
	
		switch(ch)
			{
			case 1:
				cout<<"\n Enter element to scarch from array==> ";
				cin>>x;
				m = sizeof(arr) / sizeof(arr[0]);
				result = binarySearch(arr, 0, m - 1, x);
				(result == -1) ? cout <<"\n RESULT : Element is not present in array" : cout <<"\n RESULT : Element is present at index " << result;
				break;
			
			case 2:
				return 0;
			
			default :
				cout<<"\n Wrong choice!";
			
			}
	}
		return 0;
}
