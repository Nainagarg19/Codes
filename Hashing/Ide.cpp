#include <bits/stdc++.h>
using namespace std;

    int solve(vector<int>& nums,int k)
    {
        map<int,int> mp;
        int i,xo=0,c=0,y;
        for(i=0;i<nums.size();i++)
        {
            xo=xo^nums[i];
            if(xo==k)
                c++;
            y=xo^k;
            if(mp.find(y)!=mp.end())
                c+=mp[y];
            mp[xo]+=1;
        }
        return c;
    }


int main()
{
    vector<int> nums = { 5, 6, 7, 8, 9 };
    
    int m = 5;
 
    cout<<solve(nums,  m);
    return 0;
}