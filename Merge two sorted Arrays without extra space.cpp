#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int x[]={1, 4, 7, 8, 10};
	int y[]={ 2, 3, 9 };
	int b=0,i,p;
	for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
	{
	    if(x[i]>y[0])
	    {
	        swap(x[i],y[0]);
	        sort(y, y+(sizeof(y)/sizeof(y[0])));
	    }
	}
	for(i=0;i<sizeof(x)/sizeof(x[0]);i++)
	cout<<x[i]<<" ";
	cout<<endl;
	for(i=0;i<sizeof(y)/sizeof(y[0]);i++)
	cout<<y[i]<<" ";
}
