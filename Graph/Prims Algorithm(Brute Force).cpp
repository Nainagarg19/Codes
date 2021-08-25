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
    
    vector<int> parent(n);
    vector<int> key(n,INT_MAX);
    vector<bool> mstset(n, false);
    
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int mini=INT_MAX, u;
        
        for(int j=0;j<n;j++)
        {
            if(mstset[j]==false && key[j]<mini)
            {
                mini=key[j];
                u=j;
            }
        }
        mstset[u]=true;
        for(auto it: adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(mstset[v]==false && key[v]>wt)
            {
                parent[v]=u;
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
