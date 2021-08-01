class Solution
{
public:
    void fun(int ind, int sum, vector<int> &arr, int N, vector<int> &subset)
    {
        if(ind==N)
        {
            subset.push_back(sum);
            return;
        }
        //pick that element
        fun(ind+1, sum+arr[ind], arr, N, subset);
        
        //doesnot pick that element
        fun(ind+1, sum, arr,N, subset );
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> subset;
        fun(0,0,arr,N,subset);
        sort(subset.begin(),subset.end());
        return subset;
    }
};
