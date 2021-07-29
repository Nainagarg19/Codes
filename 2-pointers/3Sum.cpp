class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
         
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> arr;
        if(nums.size()<3)
            return arr;
        for(int i=0;i<(nums.size()-2);i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int low,high,sum;
                low=i+1;
                high=nums.size()-1;
                sum=0-nums[i];
                while(low<high)
                {
                    int a=nums[low]+nums[high];
                    if(a== sum)
                    {
                        vector<int> p;
                        p.push_back(nums[i]);
                        p.push_back(nums[low]);
                        p.push_back(nums[high]);
                        arr.push_back(p);
                        while(low<high && nums[low]==nums[low+1])
                            low++;
                        while(low<high && nums[high]==nums[high-1])
                            high--;
                        low++;
                        high--;
                    }
                    else if(a>sum)
                        high--;
                    else
                        low++;
                }
            }            
        }
        return arr;
    }
};
