class Solution {
public:
    #define ll long long int
    int longestConsecutive(vector<int>& nums) {
        
        set<int> arr;
        int c=1,ans=0,p=0;
        for(int i=0;i<nums.size();i++)
            arr.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(arr.find(nums[i]-1)==arr.end())
            {
                 c=1;
                p=nums[i]+1;
                while(arr.find(p)!=arr.end())
                {
                    c++;
                    p++;
                }
            }
            ans=max(c,ans);
        }
        return ans;
    }
};
