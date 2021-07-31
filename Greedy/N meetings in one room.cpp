class Solution
{
    public:
    
    static bool sortcol(const vector<int>& v1,const vector<int>& v2 )
    {
                return v1[1] < v2[1];
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>> arr(n);
        int i=0;
        for( i=0;i<n;i++)
        {
            arr[i].push_back(start[i]);
            arr[i].push_back(end[i]);
        }
        
        sort(arr.begin(), arr.end(), sortcol);
        
        int sum=1;
        
        int limit = arr[0][1];  
    
        for(int i = 1;i<n;i++) {
            if(arr[i][0] > limit) {
                limit = arr[i][1]; 
                sum++;
            }
        }
        return sum;
        
    }
};
