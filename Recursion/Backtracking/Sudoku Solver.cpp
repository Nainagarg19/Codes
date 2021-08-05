class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board)
    {
	    for(int i=0;i<board.size();i++)
	    {
		for(int j=0;j<board[0].size();j++)
		{
            if(board[i][j]=='.')
            {
	            for(char k='1';k<='9';k++)
	            {
		            if(isValid(board, i,j,k))
		            {
			            board[i][j]=k;
			            if(solve(board))
			                return true;
			            else
			                board[i][j]='.';

                    }
                }  
                return false;
            }
        }
        }
     return true;
    }

bool isValid(vector<vector<char>> &board, int i, int j, char c)
{
	for(int x=0;x<9;x++)
	{
		if(board[i][x]==c)
		return false;

		if(board[x][j]==c)
		return false;

		if(board[3*(i/3)+(x/3)][3*(j/3)+(x%3)]==c)
		return false;
    }
    return true;
}
};
