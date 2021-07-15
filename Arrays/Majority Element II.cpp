class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,e1=-1,e2=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(e1==nums[i])
                c1++;
            else if(e2==nums[i])
                c2++;
            else if(c1==0)
            {
                e1=nums[i];
                c1++;
            }
            else if(c2==0)
            {
                e2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> arr;
        int i,c=0,c3=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==e1)
                c++;
            else if(nums[i]==e2)
                c3++;
        }
        if(c>floor(nums.size()/3))
            arr.push_back(e1);
        if(c3>floor(nums.size()/3))
            arr.push_back(e2);
        return arr;
    }
};
