class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> arr;
        int i,j,left, right,a=0,sum=0,p;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();)
        {
            for(j=i+1;j<nums.size();)
            {
                left=j+1;
                right=nums.size()-1;
                sum=target-(nums[i]+nums[j]);
                while(left<right)
                {
                    p=nums[left]+nums[right];
                    
                    if(p<sum)
                        left++;
                    else if(p>sum)
                        right--;
                    else
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        arr.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2])
                            left++;
                        while(left<right && nums[right]==temp[3])
                            right--;
                    }
                }
                j++;
                while(j<nums.size() && nums[j]==nums[j-1])
                    j++;
            }
            i++;
            while(i<nums.size() && nums[i]==nums[i-1])
                i++;
        }
        return arr;
    }
};
