
int maxLen(int A[], int n)
{
    unordered_map<int, int> mpp;
    int sum=0,len=0,p=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        
        if(sum==0)
        len=i+1;
        else{
            if(mpp.find(sum)!=mpp.end())
        {
            p=i-mpp[sum];
            len=max(len,p);
        }
        else
        {
            mpp[sum]=i;
        }
        }
   }
   return len;
}
