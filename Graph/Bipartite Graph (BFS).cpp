class Solution {
public:
    bool bipartite(vector<int>adj[],int i, vector<int>&color)
    {
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(color[it]==-1)
                {
                    q.push(it);
                    color[it]=1-color[node];
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!bipartite(adj, i, color))
	                return false;
	        }
	    }
	    return true;
	}

};
