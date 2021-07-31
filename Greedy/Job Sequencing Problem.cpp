/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a, Job b)
    {
        return (a.profit>b.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int ded=arr[0].dead;
        
        for(int i=1;i<n;i++)
        {
            ded=max(ded, arr[i].dead);
        }
        int ar[ded+1];
        for(int i=0;i<=ded;i++)
        {
            ar[i]=-1;
        }
        int p=0,c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(ar[j]==-1)
                {
                    ar[j]=i;
                    p+=arr[i].profit;
                    c++;
                    break;
                }
            }
        }
        vector<int> x;
        x.push_back(c);
        x.push_back(p);
        return x;
    } 
};
