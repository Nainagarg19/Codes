class Solution {
public:
    #define ll long long int 
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;
        unordered_map<int, int> ar;
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(ar.find(target- nums[i])!=ar.end())
            {
                result.push_back(ar[target- nums[i]]);
                result.push_back(i);
                return result;
            }
            ar[nums[i]]=i;
        }
        
        
        return result;
    }
};
