

class Solution
{
	public:
	void dfs(int node, vector<int>&vis, vector<int> adj[], stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        dfs(it, vis, adj, st);
	    }
	    st.push(node);
	}
	
	void scc(int node, vector<int>&vis, vector<int> trans[],vector<vector<int>>&ans, int &c)
	{
	    vis[node]=1;
	    
	    for(auto it: trans[node])
	    {
	        if(!vis[it])
	            scc(it, vis,trans, ans,c);
	    }
	    ans[c].emplace_back(node);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis, adj, st);
            }
        }
        
        vector<int> trans[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            trans[it].emplace_back(i);
        }
        
        vector<vector<int>> ans(V);
        int c=0;
        while(!st.empty())
        {
            int i=st.top();
            st.pop();
            if(!vis[i])
            {
                scc(i, vis, trans, ans,c);
                c++;
            }
        }
        return c;
    }
};
