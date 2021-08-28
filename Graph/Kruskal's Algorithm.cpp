#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,wt;
    node(int first, int second , int t)
    {
        u=first;
        v=second;
        wt=t;;
    }
};

bool com(node a, node b)
{
    return a.wt<b.wt;
}

int findParent(int u, vector<int> &parent)
{
    if(u==parent[u])
        return u;
    
    return parent[u]= findParent(parent[u], parent);
    
}

void unionn(int u,int v,vector<int> &parent, vector<int> &rank)
{
    u=findParent(u, parent);
    v=findParent(v, parent);
    if(rank[u]<rank[v])
        parent[u]=v;
    else if(rank[v]<rank[u])
        parent[v]=u;
    else
    {
        parent[u]=v;
        rank[v]++;
    }
}
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<node> edge;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back(node(u,v,wt));
    }
    
    sort(edge.begin(), edge.end(), com);
    
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++)
        parent[i]=i;
    
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it:edge)
    {
        if(findParent(it.u, parent)!=findParent(it.v, parent))
        {
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u,it.v, parent, rank);
        }
    }
    
    cout<<cost<<endl;
    for(auto it:mst)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
