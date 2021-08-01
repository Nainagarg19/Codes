class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0,j=0,sum=0;
        for(j=0;j<nums.size();j++)
        {
            if(nums[j]==0)
            {
                sum=max(j-i, sum);
                i=j+1;
            }             
        }
        sum=max(j-i,sum);
        return sum;
    }
    
};
