
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V+1, 0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            queue<pair<int,int>> q;
	            q.push({i,-1});
	            vis[i]=1;
	            while(!q.empty())
	            {
	                int node=q.front().first;
	                int par= q.front().second;
	                q.pop();
	                for(auto it:adj[node])
	                {
	                    if(!vis[it])
	                    {
	                        q.push({it,node});
	                        vis[it]=1;
	                    }
	                    else if(par!=it)
	                    {
	                        return true;
	                    }
	                }
	            }
	        }
	    }
	    return false;
	}
};
