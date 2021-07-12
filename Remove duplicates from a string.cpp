#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t;
string s;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>t;
	while(t--)
	{
	    vector<char> c;
	    cin>>s;
	    vector<int> mp(256,-1);
	    for(int i=0;i<s.length();i++)
	    {
	        if(mp[s[i]]==-1)
	        {  
	            mp[s[i]]++;
	            c.push_back(s[i]);
	        }
	           
	    }
	    for(int i=0;i<c.size();i++)
	    {
	        cout<<c[i];
	    }
	}
}
