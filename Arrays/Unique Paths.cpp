class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int nn=m+n-2;
        int r=m-1;
        double res=1;
        
        for(int i=1;i<=r;i++)
        {
            res=res*(nn-r+i)/i;
        }
        return (int)res;
        
    }
};
