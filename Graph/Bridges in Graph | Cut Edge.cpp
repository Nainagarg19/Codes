#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(int node, int parent, vector<int>&low, vector<int> &tin, vector<int>&vis, int &timer, vector<int> adj[])
{
    vis[node]=1;
    low[node]=timer;
    tin[node]=timer++;
    for(auto it: adj[node])
    {
        if(it==parent)
            continue;
        if(!vis[it])
        {
            dfs(it,node,low,tin,vis,timer, adj);
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;
            }
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }
    
}
int main() 
{
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> low(n,-1), tin(n,-1), vis(n,0);
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i,-1,low,tin,vis,timer, adj);
    }
    return 0;
}
