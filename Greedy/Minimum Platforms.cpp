class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=0,j=0,plat=0, sum=0;
        while(i<n)
        {
            if(arr[i]<=dep[j])
            {
                plat++;
                i++;
                sum=max(plat,sum);
            }
            else
            {
                plat--;
                j++;
            }
        }
        return sum;
    }
};
