
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool cycledfs(int node,int par,  int V, vector<int> adj[],vector<int>& vis)
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                if(cycledfs(it, node, V, adj, vis))
                    return true;
            }
            else if(par!=it)
            {
                return true;
            }
        }
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1, 0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            if(cycledfs(i,-1, V, adj,vis))
	                return true;
	        }
	    }
	    return false;
	}
};
