class Solution {
public:
    void fun(int ind, string s, vector<string> &res, vector<vector<string>> &ans)
    {
        if(ind==s.size())
{
		ans.push_back(res);
		return;
}

for(int i=ind;i<s.size();i++)
{
	if(ispalindrome(s,ind,i))
    {
	res.push_back(s.substr(ind, i- ind+1));
	fun(i+1, s, res, ans);
	res.pop_back();
}
}
    }

bool ispalindrome(string s, int start, int end)
{
	while(start<=end)
	{
		if(s[start++]!=s[end--])
			return false;
	}
	return true;
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;
        fun(0, s, res, ans);
        return ans;
    }
};


