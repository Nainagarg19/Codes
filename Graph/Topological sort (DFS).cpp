class Solution
{
	public:
	void dfs(vector<int> adj[], int i, vector<int> &vis, stack<int> &s)
	{
	    vis[i]=1;
	    for(auto it: adj[i])
	    {
	        if(vis[it]!=1)
	        {
	            dfs(adj, it, vis, s);
	        }
	    }
	    s.push(i);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> arr;
	    vector<int> vis(V,0);
	    stack<int> s;
	    for (int i=0;i<V;i++)
	    {
	        if(vis[i]!=1)
	        {
	            dfs(adj, i, vis, s);
	        }
	    }
	    while(s.empty()==false)
	    {
	        int p=s.top();
	        arr.push_back(p);
	        s.pop();
	    }
	    return arr;
	}
};
