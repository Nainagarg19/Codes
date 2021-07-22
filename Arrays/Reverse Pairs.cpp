class Solution {
public:
    int merge(vector<int>& nums, int low,int mid, int high)
    {
        int i=low,j=mid+1,ans=0;
        for(i=low;i<=mid;i++)
        {
            while(j<=high && nums[i]> 2LL *nums[j])
            {
                j++;
            }
            ans+=j-(mid+1);            
        }
        
        vector<int> temp;
        int left=low,right=mid+1;
        while(left <=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
                temp.push_back(nums[right++]);
        }
        if(left<=mid)
        {
            while(left<=mid)
            {
                temp.push_back(nums[left++]);
            }
        }
        else if(right<=high)
        {
            while(right<=high)
            {
                temp.push_back(nums[right++]);
            }
            
        }
    
        for(i=low;i<=high;i++)
        {
            nums[i]=temp[i-low];
        }
        return ans;
    }
    int mergeSort(vector<int>& nums, int low, int high)
    {
        if(low>=high)
            return 0;
        int mid=(high+low)/2;
        int ans=0;
        ans= mergeSort(nums, low,mid);
        ans+= mergeSort(nums, mid+1, high);
        ans+= merge(nums, low,mid,high);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0,nums.size()-1);
    }
};
