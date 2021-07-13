class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i,j;
        vector<vector<int>> arr(numRows);
                    
        for(i=0;i<numRows;i++)
        {
            arr[i].resize(i+1);
            arr[i][0]=1;
            arr[i][i]=1;
            
            for(j=1;j<i;j++)
            {
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            }
        }
        
        return arr;
    }
};
