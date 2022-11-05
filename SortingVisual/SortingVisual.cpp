#include "iostream"
#include "stdlib.h"
#include "time.h"

using namespace std;

void delay (float t) 
{
    double i, j;
    t = t*10000;
    for (i=1;i<=(2*t);i++)
        for (j=0;j<=10000;j++);
};

void fun (int a[], int n) 
{
    for (int i=0; i<n; i++) 
	{
    	for (int j=0; j<a[i]; j++) 
		{
			cout<<"|_";
      	}
      	cout<<"|";
      	cout<<a[i];
      	cout<<"\n\n";
    }
    delay(2);
};

void selection(int a[], int n)
{
	
	int pro, i, j, temp, min, loc;
	for ( i=0;i<n;i++) 
	{
        temp = a[i];
        min = 100;
        for ( j=i;j<n;j++) 
		{
          	if (min>a[j]) 
			{
            	min = a[j];
            	loc = j;
          	}
        }
       	a[i] = a[loc];
        a[loc] = temp;

        fun(a,n);

        delay(0.5);
        if (i==n-1)
            continue;
        else
            system("cls");
    }
}
void insertion(int a[], int n)
{	
	int pro, i, j, temp, min, loc;
	for ( i=1;i<n;i++) 
	{
        temp = a[i];
        for ( j=i-1;j>=0 && a[j]>temp;j--) 
		{
            a[j+1] = a[j];
        }
        a[j+1] = temp;

        fun(a,n);

        delay(0.5);
        if (i==n-1)
            continue;
        else
            system("cls");
    }
}

void bubble(int a[], int n)
{	
	int pro, i, j, temp, min, loc;
	for (int i=0;i<n;i++) 
	{
        for (int j=0;j<(n-1-i);j++) 
		{
        	if (a[j]>a[j+1]) 
			{
            	temp = a[j];
            	a[j] = a[j+1];
            	a[j+1] = temp;
          	}
        }

        fun(a,n);

        delay(0.5);
        if (i==n-1)
            continue;
        else
            system("cls");
    }
}

int partition(int v[], int s, int e)
{
	int pivot=v[s];
	int cnt=0;
	//counting how many elements are there greater than pivot
	for(int i=s+1; i<=e; i++)
	{
		if(pivot>=v[i]) cnt++;
	}

	//this is the partition(pivot index)
	int partInd=s+cnt;
	//put pivot in correct index
	swap(v[partInd], v[s]);

	//work for put lesser elemet than pivot in left of pivot , and put greater elements than pivot in right of pivot 
	int left=s, right=e;
	while(left<partInd and right>partInd)
	{
		while(v[left]<v[partInd]) left++; //if pivot is greater than left side element just go forward i.e. left++
		while(v[right]>v[partInd]) right--; //if pivot is lesser than right side element just go backward i.e. right--

		//now we are in that position, where fail all cases of uper 2 lines 
		if(left<partInd and right>partInd)
			swap(v[left++], v[right--]);
	}
	return partInd;
}

void quickSort(int v[], int n, int s, int e)
{
	if(s>=e) 
	{
//		fun(v, n);
		return;
	}

	//partitioning into two sections with placing the pivot in right position 
	int part=partition(v, s, e);

	//sorting left part
	quickSort(v, n, s, part-1);
	//sorting right part
	quickSort(v, n, part+1, e);
}

void quick(int v[], int n)
{
	quickSort(v, n, 0, n-1);
	fun(v, n);
}

int main () 
{
	int n, pro, i, j, temp, min, loc;
  	state : {
    	cout<<"Size of array you want to sort"<<endl;
      	cin>>n;

      	srand(time(0));
      	int a[n];
      
      	cout<<"Go for random element : choose -> 0"<<endl;
      	cout<<"Want to put numbers manually : choose -> 1"<<endl;
      	cout<<"Your choosen option is : ";
      	int option; cin>>option;
	  
	  	if(option==0)
	  	{
    		for (i=0;i<n;i++) 
	  		{
          		pro = (i+1)*n;
          		pro/=2;
          		if (pro>=40)
              		a[i] = rand() % 40;
          		else
              		a[i] = rand() % pro;
          		if (a[i] == 0)
              	a[i] = 1;
        	}
      	}
      	else
      	{
      		for(i=0; i<n; i++)
      		{
      			int num; cin>>num;
      			a[i]=num;
		  	}
	  	}

      	for (i=0;i<n;i++)
        	cout<<a[i]<<" ";

      	delay(2);
      	system("cls");

		cout<<endl;
		cout<<"Choose the algorithm you like"<<endl;
		cout<<"Selection sort : option -> 0"<<endl;
		cout<<"Insertion sort : option -> 1"<<endl;
		cout<<"Bubble sort : option -> 2"<<endl;
		cout<<"Bubble sort : option -> 3"<<endl;
		cout<<"Your choosen option is : ";
		int opt; cin>>opt;
		cout<<endl;
		switch(opt)
		{
			case 0:
				selection(a, n);
				break;
			case 1:
				insertion(a, n);
				break;
			case 2:
				bubble(a, n);
				break;
			case 3:
				quick(a, n);
				break;
			default:
				cout<<"You have choosen a wrong option. Please try again !!"<<endl;
		}
      	if(opt<4)
      	{
		  
      		for (i=0; i<n; i++)
          		cout<<a[i]<<" ";
      		cout<<"\nSORTED";
      	}
  	}
  	delay(2);
  	system("cls");

  	char ch;
  	cout<<"\nPlay again? : y/n";
  	cin>>ch;
  	if (ch=='y')
    	goto state;
  	else
    	return 0;
}
