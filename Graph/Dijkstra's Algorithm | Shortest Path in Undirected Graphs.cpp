#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m, src;
    cin>>n>>m>>src;
    vector<pair<int,int>> g[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    
    vector<int> dis(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dis[src]=0;
    pq.push({0,src});
    
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int from=pq.top().second;
        pq.pop();
        
        for(auto it: g[from])
        {
            int nextdis=it.second;
            int next= it.first;
            if(dist+nextdis<dis[next])
            {
                dis[next]=dist+nextdis;
                pq.push({dis[next],next});
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl<<dis[n];
}
