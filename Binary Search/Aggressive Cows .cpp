#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr, int pos,int cow )
{
	int cnt=1;
	int p=arr[0];
	for(int i=1;i<arr.size();i++)
	{
		if(arr[i]-p>=pos)
		{	
			cnt++;
			p=arr[i];
			if(cnt==cow)
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,c;
		cin>>n>>c;
		vector<int> arr;
		int a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		int low=1, high=arr[n-1];
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(ispossible(arr, mid, c))
			{
				low=mid+1;
			}
			else
			high=mid-1;
		}
		cout<<high<<endl;
	}
	return 0;
}
