#include<conio.h>
#include<iostream>
//#include<stdlib.h>

using namespace std;

class arr_int
{
	private :
		int a[20],i,pos,index,temp,item;

	public :

		void get_arr()
		{
			cout<<"NOTE : Index no of array starts with 0";

			for(i=0;i<5;i++)
			{
				cout<<endl<<"Enter element for position "<<i<<" -> ";
				cin>>a[i];
			}
		}
		void show_arr()
		{
				for(i=0;i<5;i++)
			{
				cout<<endl<<"Position "<<i <<"elememt of array is ==>"<<a[i];
			}
		}

		void arr_in()
		{
			cout<<endl<<"Enter the position for inserting new element....";
			cin>>pos;
			cout<<endl<<"Enter the item has to be inserted==>";
			cin>>item;
			index= (pos-1);
			temp=4;
			while(temp>=index)
				{
					if(temp>=0)
					{
						a[temp+1]=a[temp];
						temp=temp-1;
					}
					else
						break;
				}
				a[index]= item;
		}
		void arr_del()
		{
			cout<<endl<<"Enter the position for deleting an element....";
			cin>>pos;

			index= (pos-1);
			temp=index;
			while(temp<=4)
				{
					a[temp-1]=a[temp];
					temp=temp-1;
				}
			 a[4]= NULL;
		}
};

int main()
{
	arr_int obj;

	obj.get_arr();
	obj.show_arr();
	obj.arr_in();
	obj.show_arr();
	obj.arr_del();
	obj.show_arr();
	getch();
	return 0;

}
