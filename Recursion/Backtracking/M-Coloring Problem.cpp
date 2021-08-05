bool check(int node, int colour[], bool graph[101][101], int N, int col)
{
    for(int i=0;i<N;i++)
    {
        if(node!=i && graph[i][node]==1 && colour[i]==col)
            return false;
    }
    return true;
}
bool solve(int node, int colour[], int m , int N, bool graph[101][101])
{
    if(node==N)
    {
        return true;
    }
    
    for(int i=1;i<=m;i++)
    {
        if(check(node, colour, graph, N, i))
        {
            colour[node]=i;
            if(solve(node+1, colour, m , N, graph))
                return true;
            colour[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int colour[V]={0};
    if(solve(0, colour, m , V ,graph))
        return true;
    return false;
}
