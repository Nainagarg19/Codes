class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j,k;
        for(k=nums.size()-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for(j=nums.size()-1;j>k;j--)
            {
                if(nums[j]>nums[k])
                {
                    swap(nums[j], nums[k]);
                    break;
                }                    
            }
            reverse(nums.begin()+k+1,nums.end());
        }
    }
};
