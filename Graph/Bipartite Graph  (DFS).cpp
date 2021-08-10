class Solution {
public:
    bool bipartite(vector<int>adj[],int i,vector<int>&color)
    {
        if(color[i]==-1)
            color[i]=1;
        for(auto it:adj[i])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[i];
                if(!bipartite(adj, it, color))
                    return false;
            }
            else if(color[it]==color[i])
            {
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
	            if(!bipartite(adj, i,color))
	                return false;
	        }
	    }
	    return true;
	}

};
