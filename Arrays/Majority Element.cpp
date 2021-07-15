class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int c=0,e=0,i;
        for(i=0;i<nums.size();i++)
        {
            if(c==0)
            {
                e=nums[i];
            }
            if(e==nums[i])
                c++;
            else
                c--;
        }
        return e;
    }
};
