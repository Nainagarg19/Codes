class Solution
{
	public:
		//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo;
	    vector<int> deg(V,0);
	    queue<int> q;
	    for (int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        {
	            deg[it]++;
	        }
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(deg[i]==0)
	        q.push(i);
	    }
	    while(q.empty()==false)
	    {
	        int node=q.front();
	        topo.push_back(node);
	        q.pop();
	        for(auto it: adj[node])
	        {
	            deg[it]--;
	            if(deg[it]==0)
	            q.push(it);
	        }
	    }
	    
	    return topo;
	}
};
