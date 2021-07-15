class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i,j,n=matrix.size();
        bool ans=false;
        for(i=0;i<n;i++)
        {
            if(target<matrix[i][0])
            {
                break;
            }
        }
        if(i==n)
           i=n-1;
        else if(i!=0)
            i--;
        else 
            return ans;
        for(j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==target)
                ans=true;
        }
        return ans;
        
    }
};
