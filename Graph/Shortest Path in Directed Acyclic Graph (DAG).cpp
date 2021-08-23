#include<bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,int>> vec[], vector<int>& vis, int node, stack<int>& s)
{
    vis[node]=1;
    for(auto it: vec[node])
    {
        if(!vis[it.first])
            dfs(vec, vis,it.first,s );
    }
    s.push(node);
}
void fun(int src, int n, vector<pair<int,int>> vec[])
{
    vector<int> vis(n,0);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(vec, vis, i, s);
    }
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(dis[node]!=INT_MAX)
        {
            for(auto it: vec[node])
            {
                if(dis[node]+it.second < dis[it.first])
                    dis[it.first]=dis[node]+it.second;
            }
        }
    }
    cout<<dis[n-2];
    
}
int main() {
	int n, m;
	cin>>n>>m;
	vector<pair<int,int>> vec[n];
	for(int i=0;i<m;i++)
	{
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    vec[u].push_back({v,wt});
	}
	fun(0, n, vec);
	return 0;
}
