#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=1;i<=m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MAX);
    vector<bool> mstset(n, false);
    
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        mstset[u]=true;
        for(auto it: adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mstset[v]==false && key[v]>wt)
            {
                parent[v]=u;
                pq.push({wt,v});
                key[v]=wt;
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return 0;
}
